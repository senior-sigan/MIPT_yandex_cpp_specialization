#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Year {
 public:
  explicit Year(int value) : value(value) {}

  int GetValue() const {
    return value;
  }

 private:
  int value;
};

class Month {
 public:
  explicit Month(int value) {
    if (value < 1 || value > 12) {
      throw runtime_error("Month value is invalid: " + to_string(value));
    }
    this->value = value;
  };

  int GetValue() const {
    return value;
  }

 private:
  int value;
};

class Day {
 public:
  explicit Day(int value) {
    if (value < 1 || value > 31) {
      throw runtime_error("Day value is invalid: " + to_string(value));
    }
    this->value = value;
  };

  int GetValue() const {
    return value;
  }

 private:
  int value;
};

class Date {
 public:
  Date(const Year& year, const Month& month, const Day& day) : year(year), month(month), day(day) {}

  int GetYear() const {
    return year.GetValue();
  }
  int GetMonth() const {
    return month.GetValue();
  }
  int GetDay() const {
    return day.GetValue();
  }

  bool operator<(const Date& rhs) const {
    if (GetYear() == rhs.GetYear()) {
      if (GetMonth() == rhs.GetMonth()) {
        if (GetDay() == rhs.GetDay()) {
          return false;
        } else {
          return GetDay() < rhs.GetDay();
        }
      } else {
        return GetMonth() < rhs.GetMonth();
      }
    } else {
      return GetYear() < rhs.GetYear();
    }
  }

 private:
  Year year;
  Month month;
  Day day;
};

ostream& operator<<(ostream& stream, const Date& date) {
  stream << setw(4) << setfill('0') << date.GetYear() << '-';
  stream << setw(2) << setfill('0') << date.GetMonth() << '-';
  stream << setw(2) << setfill('0') << date.GetDay();
  return stream;
}

class Database {
 public:
  void AddEvent(const Date& date, const string& event) {
    db[date].insert(event);
  }
  bool DeleteEvent(const Date& date, const string& event) {
    if (db[date].count(event) == 0) {
      return false;
    } else {
      db[date].erase(event);
      return true;
    }
  }
  int DeleteEvent(const Date& date) {
    int to_delete = db[date].size();
    db[date].clear();
    return to_delete;
  }

  void Find(const Date& date) const {
    if (db.count(date) == 0) return;
    for (const auto& ev : db.at(date)) {
      cout << ev << endl;
    }
  }

  void Print() const {
    for (const auto& kv : db) {
      const auto& date = kv.first;
      for (const auto& ev : kv.second) {
        cout << date << " " << ev << endl;
      }
    }
  }

 private:
  map<Date, set<string>> db;
};

namespace Parser {
void check_next_symbol(stringstream& ss, const string& str) {
  if (ss.peek() != '-') {
    throw runtime_error("Wrong date format: " + str);
  }
  ss.ignore(1);
}

void check_end_of_stream(stringstream& ss, const string& str) {
  if (ss.peek() != -1) {
    throw runtime_error("Wrong date format: " + str);
  }
}

Date ParseDate(const string& str) {
  stringstream ss(str);
  int y, m, d;
  ss >> y;
  Year year(y);
  check_next_symbol(ss, str);
  ss >> m;
  Month month(m);
  check_next_symbol(ss, str);
  ss >> d;
  Day day(d);
  check_end_of_stream(ss, str);
  return Date(year, month, day);
}

void ParseLine(Database& db, const string& line) {
  stringstream ss(line);
  string cmd;
  ss >> cmd;
  if (cmd == "Add") {
    string date;
    string ev;
    ss >> date >> ev;
    db.AddEvent(ParseDate(date), ev);
  } else if (cmd == "Find") {
    string date;
    ss >> date;
    db.Find(ParseDate(date));
  } else if (cmd == "Del") {
    string date;
    ss >> date;
    if (ss.peek() == -1) {
      int cnt = db.DeleteEvent(ParseDate(date));
      cout << "Deleted " << cnt << " events" << endl;
    } else {
      string ev;
      ss >> ev;
      if (db.DeleteEvent(ParseDate(date), ev)) {
        cout << "Deleted successfully" << endl;
      } else {
        cout << "Event not found" << endl;
      }
    }
  } else if (cmd == "Print") {
    db.Print();
  } else if (cmd.size() == 0) {
    // skip
  } else {
    cout << "Unknown command: " << cmd << endl;
  }
}
}

// namespace Tests {
// void test1() {
//   Database db;

//   db.AddEvent(Date(Year(0), Month(1), Day(2)), "event1");
//   db.AddEvent(Date(Year(1), Month(2), Day(3)), "event2");
//   db.Print();
//   db.DeleteEvent(Date(Year(0), Month(1), Day(2)));
//   db.Print();
//   db.DeleteEvent(Date(Year(1), Month(2), Day(3)));
//   db.Print();
// }
// void test_date_1() {
//   cout << Parser::ParseDate("2018-01-29") << endl;
//   cout << Parser::ParseDate("2018-01-29") << endl;
//   cout << Parser::ParseDate("-1-1-1") << endl;
//   cout << Parser::ParseDate("1-1-1") << endl;
//   try {
//     Parser::ParseDate("1--1-1");
//     exit(-1);
//   } catch (exception& ex) {
//     cout << ex.what() << endl;
//   }
//   try {
//     Parser::ParseDate("1---1-1");
//     exit(-1);
//   } catch (exception& ex) {
//     cout << ex.what() << endl;
//   }
//   try {
//     Parser::ParseDate("lol1-1-1");
//     exit(-1);
//   } catch (exception& ex) {
//     cout << ex.what() << endl;
//   }
//   try {
//     Parser::ParseDate("1-1-1asd");
//     exit(-1);
//   } catch (exception& ex) {
//     cout << ex.what() << endl;
//   }
// }
// }

int main() {
  // Tests::test_date_1();
  Database db;

  string command;
  while (getline(cin, command)) {
    try {
      Parser::ParseLine(db, command);
    } catch (runtime_error& err) {
      cout << err.what() << endl;
      return 0;
    }
  }

  return 0;
}
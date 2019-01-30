#include "database.h"
#include <sstream>

using namespace std;

void Database::Add(const Date& date, const std::string& event) {
  auto res = db[date].insert(event);
  if (res.second) {
    db_ordered[date].push_back(event);
  }
}

std::string Database::Last(const Date& date) const {
  Date last = date;
  for (const auto& kv : db_ordered) {
    const auto& d = kv.first;
    if (d > date) {
      break;
    } else {
      if (!kv.second.empty()) last = d;
    }
  }

  if (db_ordered.count(last) == 0) return "No entries";
  auto events = db_ordered.at(last);
  if (events.empty()) return "No entries";
  ostringstream ss;
  ss << last << " " << events.at(events.size() - 1);
  return ss.str();
}

void Database::Print(std::ostream& out) const {
  for (const auto& kv : db_ordered) {
    const auto& date = kv.first;
    for (const auto& ev : kv.second) {
      out << date << " " << ev << endl;
    }
  }
}

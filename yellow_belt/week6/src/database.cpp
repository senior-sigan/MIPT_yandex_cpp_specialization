#include "database.h"
#include <sstream>

using namespace std;

void Database::Add(const Date& date, const std::string& event) {
  auto res = db[date].insert(event);
  if (res.second) {
    db_ordered[date].push_back(event);
  }
}

std::string Database::Last(const Date& date) {
  Date last = date;
  for (const auto& kv : db_ordered) {
    const auto& d = kv.first;
    if (d > date) {
      break;
    } else {
      if (!kv.second.empty()) last = d;
    }
  }

  auto events = db_ordered[last];
  if (events.empty()) return "No entries";
  ostringstream ss;
  ss << last << " " << events.at(events.size() - 1);
  return ss.str();
}

void Database::Print(std::ostream& out) {
  for (const auto& kv : db_ordered) {
    const auto& date = kv.first;
    for (const auto& ev : kv.second) {
      out << date << " " << ev << endl;
    }
  }
}

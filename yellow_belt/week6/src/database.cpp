#include "database.h"
#include <sstream>

using namespace std;

void Database::Add(const Date &date, const std::string &event) {
  if (db[date].insert(event).second) {
    db_ordered[date].push_back(event);
  }
}

std::string Database::Last(const Date& date) const {
  auto i = db_ordered.upper_bound(date);

  if (db_ordered.empty()) return "No entries";
  if (i == begin(db_ordered)) return "No entries";

  i = prev(i);
  ostringstream ss;
  ss << i->first << " " << *prev(i->second.end());
  return ss.str();
}

void Database::Print(std::ostream &out) const {
  for (const auto &kv : db_ordered) {
    const auto &date = kv.first;
    for (const auto &ev : kv.second) {
      out << date << " " << ev << endl;
    }
  }
}

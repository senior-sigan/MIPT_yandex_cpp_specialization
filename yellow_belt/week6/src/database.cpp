#include "database.h"

using namespace std;

void Database::Add(const Date &date, const std::string& event) {
  db[date].insert(event);
}

std::string Database::Last(const Date &date) {
  return "No entries";
}

void Database::Print(std::ostream &out) {
  for (const auto& kv : db) {
    const auto& date = kv.first;
    for (const auto& ev : kv.second) {
      out << date << " " << ev << endl;
    }
  }
}

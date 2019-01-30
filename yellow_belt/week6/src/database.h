#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include "date.h"

class Database {
  std::map<Date, std::set<std::string>> db;
  std::map<Date, std::vector<std::string>> db_ordered;

 public:
  void Add(const Date &date, const std::string &event);

  template<typename BinaryPredicate>
  int RemoveIf(BinaryPredicate predicate) {
    int removed = 0;
    std::set<Date> empty_keys;
    for (const auto &kv : db_ordered) {
      const auto &date = kv.first;
      auto &vec = db_ordered[date];
      auto to_delete = std::stable_partition(begin(vec), end(vec),
                                             [predicate, date](const std::string &ev) { return !predicate(date, ev); });
      removed += end(vec) - to_delete;
      vec.erase(to_delete, end(vec));
      db[date] = std::set<std::string>(begin(vec), end(vec));
      if (vec.empty()) empty_keys.insert(date);
    }

    for (const auto &k: empty_keys) {
      db.erase(k);
      db_ordered.erase(k);
    }

    return removed;
  }

  template<typename BinaryPredicate>
  std::vector<std::string> FindIf(BinaryPredicate predicate) const {
    std::vector<std::string> res;
    for (const auto &kv : db_ordered) {
      const auto &date = kv.first;
      for (const auto &ev : kv.second) {
        if (predicate(date, ev)) {
          std::stringstream ss;
          ss << date << " " << ev;
          res.emplace_back(ss.str());
        }
      }
    }

    return res;
  }

  std::string Last(const Date &date) const;

  void Print(std::ostream &out) const;
};
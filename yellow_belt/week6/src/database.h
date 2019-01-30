#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "date.h"
#include <strstream>
#include <algorithm>

class Database {
  std::map<Date, std::set<std::string>> db;
  std::map<Date, std::vector<std::string>> db_ordered;
 public:
  void Add(const Date &date, const std::string &event);

  template<typename BinaryPredicate>
  int RemoveIf(BinaryPredicate predicate) {
    int removed = 0;
    for (const auto &kv : db_ordered) {
      const auto &date = kv.first;
      auto& vec = db_ordered[date];
      auto to_delete = std::stable_partition(begin(vec), end(vec), [predicate, date](const std::string &ev) {
        return predicate(date, ev);
      });
      auto len = to_delete - begin(vec);
      removed += len;
      vec.erase(begin(vec), to_delete);

      if (len > 0) {
        db[date] = std::set<std::string>(begin(vec), end(vec));
      }
    }

    return removed;
  }

  template<typename BinaryPredicate>
  std::vector<std::string> FindIf(BinaryPredicate predicate) {
    std::vector<std::string> res;
    for (const auto &kv : db_ordered) {
      const auto &date = kv.first;
      for (const auto &ev : kv.second) {
        if (predicate(date, ev)) {
          std::strstream ss;
          ss << date << " " << ev;
          res.emplace_back(ss.str());
        }
      }
    }

    return res;
  }

  std::string Last(const Date &date);

  void Print(std::ostream &out);
};
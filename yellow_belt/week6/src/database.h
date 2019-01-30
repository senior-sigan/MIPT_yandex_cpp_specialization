#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "date.h"

class Database {
  std::map<Date, std::set<std::string>> db;
 public:
  void Add(const Date& date, const std::string& event);

  template<typename BinaryPredicate>
  int RemoveIf(BinaryPredicate predicate) {
    return 0;
  }

  template<typename BinaryPredicate>
  std::vector<std::string> FindIf(BinaryPredicate predicate) {
    return {};
  }

  std::string Last(const Date& date);

  void Print(std::ostream& out);
};
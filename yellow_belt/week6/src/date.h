#pragma once

#include <ostream>

class Date {
  int year;
  int month;
  int day;
 public:
  Date(int year, int month, int day) : year(year), month(month), day(day) {}

  int GetYear() const {
    return year;
  }
  int GetMonth() const {
    return month;
  }
  int GetDay() const {
    return day;
  }

  bool operator==(const Date &rhs) const {
    return std::tie(year, month, day) == std::tie(rhs.year, rhs.month, rhs.day);
  }
  bool operator!=(const Date &rhs) const {
    return !(rhs == *this);
  }

  bool operator<(const Date &rhs) const {
    return std::tie(year, month, day) < std::tie(rhs.year, rhs.month, rhs.day);
  }
  bool operator>(const Date &rhs) const {
    return rhs < *this;
  }
  bool operator<=(const Date &rhs) const {
    return !(rhs < *this);
  }
  bool operator>=(const Date &rhs) const {
    return !(*this < rhs);
  }

  friend std::ostream &operator<<(std::ostream &os, const Date &date);
};

Date ParseDate(std::istream &is);
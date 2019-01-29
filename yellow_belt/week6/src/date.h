#pragma once

#include <iostream>

class Date {
 public:
  Date(int year, int month, int day);
};

Date ParseDate(std::istream& is);
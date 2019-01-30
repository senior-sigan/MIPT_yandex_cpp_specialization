#include "date.h"
#include <stdexcept>

void checkDelimiter(std::istream &is) {
  char ch;
  is >> ch;
  if (ch != '-') throw std::logic_error("Unknown date delimiter " + std::to_string(ch));
}

Date ParseDate(std::istream &is) {
  int year, month, day;
  is >> year;
  if (year < 0 || year > 9999) throw std::logic_error("Year should be in [0, 9999] but " + std::to_string(year));
  checkDelimiter(is);
  is >> month;
  if (month < 1 || month > 12) throw std::logic_error("Month should be in [1,12] but " + std::to_string(month));
  checkDelimiter(is);
  is >> day;
  if (day < 1 || day > 31) throw std::logic_error("Day should be in [1,31] but "+ std::to_string(day));
  return {year, month, day};
}
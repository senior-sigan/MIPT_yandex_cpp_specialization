#pragma once

#include "database.h"
#include <string>
#include <ostream>

class App {
  Database db;
  std::ostream& out;
 public:
  explicit App(std::ostream& out): out(out) {}
  void ReadLine(const std::string& line);
};
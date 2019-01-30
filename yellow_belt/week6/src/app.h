#pragma once

#include <ostream>
#include <string>
#include "database.h"

class App {
  Database db;
  std::ostream& out;

 public:
  explicit App(std::ostream& out) : out(out) {}
  void ReadLine(const std::string& line);
};
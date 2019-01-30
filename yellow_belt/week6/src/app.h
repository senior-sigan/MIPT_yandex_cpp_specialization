#pragma once

#include "database.h"
#include <string>

class App {
  Database db;
 public:
  void ReadLine(const std::string& line);
};
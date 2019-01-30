#include "event_parser.h"
#include <string>

using namespace std;

string ParseEvent(istream& is) {
  string line;
  is >> ws; // skip leading whitespaces
  getline(is, line);
  return line;
}
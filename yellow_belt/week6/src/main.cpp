#include "tests/tests.h"
#include "app.h"
#include <iostream>

using namespace std;

int main() {
  TestAll();

  App app(cout);

  for (string line; getline(cin, line);) {
    app.ReadLine(line);
  }

  return 0;
}

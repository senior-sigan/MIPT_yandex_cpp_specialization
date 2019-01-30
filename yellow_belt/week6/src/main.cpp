#include <iostream>
#include "app.h"
#include "tests.h"

using namespace std;

int main() {
  TestAll();

  App app(cout);

  for (string line; getline(cin, line);) {
    app.ReadLine(line);
  }

  return 0;
}

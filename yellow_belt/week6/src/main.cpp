#include "tests/tests.h"
#include "app.h"

using namespace std;

int main() {
  TestAll();

  App app;

  for (string line; getline(cin, line);) {
    app.ReadLine(line);
  }

  return 0;
}

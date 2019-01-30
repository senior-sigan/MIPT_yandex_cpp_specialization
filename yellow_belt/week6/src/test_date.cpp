#include <sstream>
#include <stdexcept>
#include "date.h"
#include "test_runner.h"
#include "tests.h"
using namespace std;

void TestDateParser() {
  {
    istringstream is("2017-11-18");
    AssertEqual(ParseDate(is), Date{2017, 11, 18}, "2017-11-18 test");
  }
  {
    istringstream is("2017-13-18");
    try {
      ParseDate(is);
      Assert(false, "2017-13-18 should not be parsed!");
    } catch (exception& ex) {
      // OK
    }
  }
}
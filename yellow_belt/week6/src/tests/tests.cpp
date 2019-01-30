#include "tests.h"
#include "test_runner.h"

void TestAll() {
  TestRunner tr;
  tr.RunTest(TestDateParser, "TestDateParser");
  tr.RunTest(TestParseEvent, "TestParseEvent");
  tr.RunTest(TestParseCondition, "TestParseCondition");
}
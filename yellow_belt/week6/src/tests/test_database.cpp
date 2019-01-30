#include "test_runner.h"
#include "tests.h"
#include "../app.h"
#include <string>

using namespace std;

void TestDatabase() {
  cerr << "=============" << endl;
  {
    App app(cerr);
    app.ReadLine("Add 2017-01-01 Holiday");
    app.ReadLine("Add 2017-03-08 Holiday");
    app.ReadLine("Add 2017-1-1 New Year");
    app.ReadLine("Add 2017-1-1 New Year");
    app.ReadLine("Print");
  }
  cerr << "=============" << endl;
  {
    App app(cerr);
    app.ReadLine("Add 2017-06-01 1st of June");
    app.ReadLine("Add 2017-07-08 8th of July");
    app.ReadLine("Add 2017-07-08 Someone's birthday");
    app.ReadLine("Del date == 2017-07-08");
  }
  cerr << "=============" << endl;
  {
    App app(cerr);
    app.ReadLine("Add 2017-01-01 Holiday");
    app.ReadLine("Add 2017-03-08 Holiday");
    app.ReadLine("Add 2017-01-01 New Year");
    app.ReadLine("Find event != \"working day\"");
    app.ReadLine("Add 2017-05-09 Holiday");
  }
  cerr << "=============" << endl;
  {
    App app(cerr);
    app.ReadLine("Add 2017-01-01 New Year");
    app.ReadLine("Add 2017-03-08 Holiday");
    app.ReadLine("Add 2017-01-01 Holiday");
    app.ReadLine("Last 2016-12-31");
    app.ReadLine("Last 2017-01-01");
    app.ReadLine("Last 2017-06-01");
    app.ReadLine("Add 2017-05-09 Holiday");
  }
  cerr << "=============" << endl;
  {
    App app(cerr);
    app.ReadLine("Add 2017-11-21 Tuesday");
    app.ReadLine("Add 2017-11-20 Monday");
    app.ReadLine("Add 2017-11-21 Weekly meeting");
    app.ReadLine("Print");
    app.ReadLine("Find event != \"Weekly meeting\"");
    app.ReadLine("Last 2017-11-30");
    app.ReadLine("Del date > 2017-11-20");
    app.ReadLine("Last 2017-11-30");
    app.ReadLine("Last 2017-11-01");
  }
  cerr << "=============" << endl;
}
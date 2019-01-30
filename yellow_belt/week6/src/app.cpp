#include "app.h"
#include "date.h"
#include "node.h"
#include "event_parser.h"
#include "condition_parser.h"
#include <sstream>

using namespace std;

void App::ReadLine(const std::string &line) {
  istringstream is(line);

  string command;
  is >> command;
  if (command == "Add") {
    const auto date = ParseDate(is);
    const auto event = ParseEvent(is);
    db.Add(date, event);
  } else if (command == "Print") {
    db.Print(out);
  } else if (command == "Del") {
    auto condition = ParseCondition(is);
    auto predicate = [condition](const Date& date, const string& event) { return condition->Evaluate(date, event); };
    int count = db.RemoveIf(predicate);
    out << "Removed " << count << " entries" << endl;
  } else if (command == "Find") {
    auto condition = ParseCondition(is);
    auto predicate = [condition](const Date& date, const string& event) { return condition->Evaluate(date, event); };

    const auto entries = db.FindIf(predicate);
    for (const auto& entry : entries) {
      out << entry << endl;
    }
    out << "Found " << entries.size() << " entries" << endl;
  } else if (command == "Last") {
    try {
      out << db.Last(ParseDate(is)) << endl;
    } catch (invalid_argument&) {
      out << "No entries" << endl;
    }
  } else if (command.empty()) {
    return;
  } else {
    throw logic_error("Unknown command: " + command);
  }
}

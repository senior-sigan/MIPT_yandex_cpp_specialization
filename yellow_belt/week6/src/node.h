#pragma once

#include <memory>
#include <string>
#include "date.h"

class Node {
 public:
  virtual bool Evaluate(const Date& date, const std::string& s) {
    return false;
  }
};
class EmptyNode : public Node {};

enum class Comparison { Less, LessOrEqual, Greater, GreaterOrEqual, Equal, NotEqual };
enum class LogicalOperation { And, Or };

class DateComparisonNode : public Node {
 public:
  DateComparisonNode(const Comparison& cmp, const Date& date) {}
};

class EventComparisonNode : public Node {
 public:
  EventComparisonNode(const Comparison& cmp, const std::string& value) {}
};

class LogicalOperationNode : public Node {
 public:
  LogicalOperationNode(const LogicalOperation& logical_operation, std::shared_ptr<Node> left,
                       std::shared_ptr<Node> right) {}
};
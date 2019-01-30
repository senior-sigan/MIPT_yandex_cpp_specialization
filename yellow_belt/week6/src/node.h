#pragma once

#include <memory>
#include <string>
#include "date.h"

class Node {
 public:
  virtual bool Evaluate(const Date &date, const std::string &s) const;
  virtual ~Node() = default;
};
class EmptyNode : public Node {};

enum class Comparison { Less, LessOrEqual, Greater, GreaterOrEqual, Equal, NotEqual };
enum class LogicalOperation { And, Or };

class DateComparisonNode : public Node {
  const Comparison cmp;
  const Date right_date;

 public:
  DateComparisonNode(const Comparison &cmp, const Date &date) : cmp(cmp), right_date(date) {}
  bool Evaluate(const Date &date, const std::string &s) const override;
};

class EventComparisonNode : public Node {
  const Comparison cmp;
  const std::string value;

 public:
  EventComparisonNode(const Comparison &cmp, const std::string &value) : cmp(cmp), value(value) {}
  bool Evaluate(const Date &date, const std::string &s) const override;
};

class LogicalOperationNode : public Node {
  const LogicalOperation op;
  const std::shared_ptr<Node> left;
  const std::shared_ptr<Node> right;

 public:
  LogicalOperationNode(const LogicalOperation &logical_operation, const std::shared_ptr<Node> &left,
                       const std::shared_ptr<Node> &right)
      : op(logical_operation), left(left), right(right) {}
  bool Evaluate(const Date &date, const std::string &s) const override;
};
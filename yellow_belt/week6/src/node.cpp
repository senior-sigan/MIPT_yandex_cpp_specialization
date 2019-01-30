#include "node.h"
#include <iostream>

using namespace std;

template<typename T>
bool Compare(const Comparison &cmp, T left, T right) {
  if (cmp == Comparison::Equal) return left == right;
  if (cmp == Comparison::NotEqual) return left != right;
  if (cmp == Comparison::Greater) return left > right;
  if (cmp == Comparison::GreaterOrEqual) return left >= right;
  if (cmp == Comparison::Less) return left < right;
  if (cmp == Comparison::LessOrEqual) return left <= right;

  cerr << "Unknown Comparision" << endl;
  return false;
}

bool EventComparisonNode::Evaluate(const Date &date, const std::string &s) {
  return Compare(cmp, s, value);
}
bool DateComparisonNode::Evaluate(const Date &date, const std::string &s) {
  return Compare(cmp, date, right_date);
}
bool LogicalOperationNode::Evaluate(const Date &date, const std::string &s) {
  if (op == LogicalOperation::And) return left->Evaluate(date, s) && right->Evaluate(date, s);
  if (op == LogicalOperation::Or) return left->Evaluate(date, s) || right->Evaluate(date, s);

  cerr << "Unknown LogicalOperation" << endl;
  return false;
}
bool Node::Evaluate(const Date &date, const std::string &s) {
  cout << "Node.Evaluate " << date << " " << s << endl;
  return false;
}

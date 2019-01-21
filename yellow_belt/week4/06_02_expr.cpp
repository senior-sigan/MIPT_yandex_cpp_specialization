/**
 * Реализуйте построение арифметического выражения согласно следующей схеме:
 *
 * - изначально есть выражение, состоящее из некоторого целого числа x;
 * - на каждом шаге к текущему выражению применяется некоторая операция: прибавление числа, вычитание числа, умножение
 * на число или деление на число; перед применением операции выражение всегда должно быть заключено в скобки.
 *
 * Модифицируйте решение предыдущей части так, чтобы предыдущее выражение обрамлялось скобками лишь при необходимости,
 * то есть только в том случае, когда очередная операция имеет бо́льший приоритет, чем предыдущая.
 */

#include <iostream>
#include <map>
#include <queue>
#include <stack>

using namespace std;

const map<string, int> priority = {{"", 100500}, {"-", 0}, {"+", 0}, {"*", 1}, {"/", 1}};

struct opnum {
  string op;
  string num;
};

const opnum empty_opnum = {"", ""};

string SafeBack(const queue<opnum>& c, const string& default_) {
  if (c.size() == 0) return default_;
  return c.back().op;
}

int main() {
  int x;
  cin >> x;
  int n;
  cin >> n;
  queue<opnum> calls;
  int braces = 0;
  for (int i = 0; i < n; i++) {
    opnum o;
    cin >> o.op >> o.num;
    if (priority.at(SafeBack(calls, "")) < priority.at(o.op)) {
      braces++;
    }
    calls.push(o);
  }

  for (int i = 0; i < braces; i++) {
    cout << "(";
  }
  cout << x;
  string prev = "";
  while (!calls.empty()) {
    auto o = calls.front();
    if (priority.at(prev) < priority.at(o.op)) {
      cout << ")";
    }
    prev = o.op;
    cout << " " << o.op << " " << o.num;
    calls.pop();
  }
}
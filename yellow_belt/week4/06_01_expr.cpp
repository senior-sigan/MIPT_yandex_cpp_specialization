/**
 * Реализуйте построение арифметического выражения согласно следующей схеме:
 *
 * - изначально есть выражение, состоящее из некоторого целого числа x;
 * - на каждом шаге к текущему выражению применяется некоторая операция: прибавление числа, вычитание числа, умножение
 * на число или деление на число; перед применением операции выражение всегда должно быть заключено в скобки.
 */

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct opnum {
  string op;
  string num;
};

int main() {
  int x;
  cin >> x;
  int n;
  cin >> n;
  queue<opnum> calls;
  for (int i = 0; i < n; i++) {
    opnum o;
    cin >> o.op >> o.num;
    calls.push(o);
  }

  for (int i = 0; i < n; i++) {
    cout << "(";
  }
  cout << x;
  while (!calls.empty()) {
    auto o = calls.front();
    cout << ") " << o.op << " " << o.num;
    calls.pop();
  }
}
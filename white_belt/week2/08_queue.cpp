/**
 * Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить в конец и уходить оттуда.
 * Более того, иногда некоторые люди могут прекращать и начинать беспокоиться из-за того, что очередь не продвигается.
 *
 * Реализуйте обработку следующих операций над очередью:
 *
 * - WORRY i: пометить i-го человека с начала очереди (в нумерации с 0) как беспокоящегося;
 * - QUIET i: пометить i-го человека как успокоившегося;
 * - COME k: добавить k спокойных человек в конец очереди;
 * - COME -k: убрать k человек из конца очереди;
 * - WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
 *
 * Изначально очередь пуста.
 *
 * # Формат ввода
 *
 * Количество операций Q, затем описания операций.
 *
 * Для каждой операции WORRY i и QUIET i гарантируется, что человек с номером i существует в очереди на момент операции.
 *
 * Для каждой операции COME -k гарантируется, что k не больше текущего размера очереди.
 *
 * # Формат вывода
 *
 * Для каждой операции WORRY_COUNT выведите одно целое число — количество беспокоящихся людей в очереди.
 *
 * # Пример
 *
 * ```
 * 8
 * COME 5
 * WORRY 1
 * WORRY 4
 * COME -2
 * WORRY_COUNT
 * COME 3
 * WORRY 3
 * WORRY_COUNT
 * ```
 **/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Queue {
  vector<bool> v;

 public:
  void worry(int i) {
    v[i] = true;
  }
  void quite(int i) {
    v[i] = false;
  }
  void come_in(int k) {
    v.resize(v.size() + k, false);
    // cout << "DEBUG: come_in size=" << v.size() << endl;
  }
  void come_out(int k) {
    v.resize(v.size() - k);
    // cout << "DEBUG: come_out size=" << v.size() << endl;
  }
  int worry_count() {
    return count(v.begin(), v.end(), true);
  }
};

void handle(Queue& queue) {
  // TODO: It should be a map and state machine
  string op;
  cin >> op;
  if (op == "WORRY_COUNT") {
    cout << queue.worry_count() << endl;
  } else if (op == "COME") {
    int k;
    cin >> k;
    if (k > 0) {
      queue.come_in(k);
    } else {
      queue.come_out(-k);
    }
  } else if (op == "WORRY") {
    int k;
    cin >> k;
    queue.worry(k);
  } else if (op == "QUIET") {
    int k;
    cin >> k;
    queue.quite(k);
  }
}

int main(int argc, char const* argv[]) {
  Queue queue;
  int operations;
  cin >> operations;
  for (; operations > 0; operations--) {
    handle(queue);
  }
  return 0;
}

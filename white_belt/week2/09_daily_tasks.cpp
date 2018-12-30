/**
У каждого из нас есть ежемесячные дела, каждое из которых нужно выполнять в конкретный день каждого месяца: оплата
счетов за электричество, абонентская плата за связь и пр. Вам нужно реализовать работу со списком таких дел, а именно,
обработку следующих операций:

ADD i s
Добавить дело с названием s в день i.

NEXT
Закончить текущий месяц и начать новый. Если новый месяц имеет больше дней, чем текущий, добавленные дни изначально не
будут содержать дел. Если же в новом месяце меньше дней, дела со всех удаляемых дней необходимо будет переместить на
последний день нового месяца.

Обратите внимание, что количество команд этого типа может превышать 11.

DUMP i
Вывести все дела в день i.

Изначально текущим месяцем считается январь.
Количества дней в месяцах соответствуют Григорианскому календарю с той лишь разницей, что в феврале всегда 28 дней.

# Формат ввода
Сначала число операций Q, затем описания операций.

Названия дел s уникальны и состоят только из латинских букв, цифр и символов подчёркивания.
Номера дней i являются целыми числами и нумеруются от 1 до размера текущего месяца.

# Формат вывода
Для каждой операции типа DUMP в отдельной строке выведите количество дел в соответствующий день, а затем их названия,
разделяя их пробелом. Порядок вывода дел в рамках каждой операции значения не имеет.

# Пример
```
12
ADD 5 Salary
ADD 31 Walk
ADD 30 WalkPreparations
NEXT
DUMP 5
DUMP 28
NEXT
DUMP 31
DUMP 30
DUMP 28
ADD 28 Payment
DUMP 28
```
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Day {
  vector<string> tasks;

 public:
  void add(string task) {
    tasks.push_back(task);
  }

  void add(const Day& day) {
    for (auto task : day.tasks) {
      add(task);
    }
  }

  void print() {
    cout << tasks.size();
    if (!tasks.empty()) {
      for (auto task : tasks) {
        cout << " " << task;
      }
    }
    cout << endl;
  }
};

class Tasks {
  const vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int current_month = 0;
  vector<Day> calendar;

 public:
  Tasks() : calendar(days[current_month]){};

  void add(string task, int day) {
    if (day <= calendar.size()) {
      calendar[day - 1].add(task);
    }
  }

  void next() {
    int prev_d = days[current_month];
    if (++current_month > 11) current_month = 0;
    int d = days[current_month];
    if (d < prev_d) {
      for (int i = d; i < prev_d; i++) {
        calendar[d - 1].add(calendar[i]);
      }
    }
    calendar.resize(d);
  }

  void dump(int i) {
    if (i <= calendar.size()) {
      calendar[i - 1].print();
    }
  }

  /**
   * Just to debug the code :)
   */
  void print() {
    int i = 1;
    for (auto day : calendar) {
      cout << "  " << i++ << " ";
      day.print();
    }
  }
};

// TODO: it should be state machine with map.
void handle(Tasks& tasks) {
  string op;
  cin >> op;

  if (op == "ADD") {
    int day;
    string task;
    cin >> day >> task;
    tasks.add(task, day);
  } else if (op == "NEXT") {
    tasks.next();
  } else if (op == "DUMP") {
    int day;
    cin >> day;
    tasks.dump(day);
  } else if (op == "PRINT") {
    tasks.print();
  }
}

int main(int argc, char const* argv[]) {
  Tasks tasks;
  int q;
  cin >> q;
  for (; q > 0; q--) {
    handle(tasks);
  }
  return 0;
}

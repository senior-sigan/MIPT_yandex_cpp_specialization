#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

ostream& operator<<(ostream& out, const TaskStatus& status) {
  string statusName;
  switch (status) {
    case TaskStatus::NEW:
      statusName = "\"NEW\"";
      break;
    case TaskStatus::IN_PROGRESS:
      statusName = "\"IN_PROGRESS\"";
      break;
    case TaskStatus::TESTING:
      statusName = "\"TESTING\"";
      break;
    case TaskStatus::DONE:
      statusName = "\"DONE\"";
      break;
  }
  return out << statusName;
}

#include "./04_team_tasks.cpp"

template<typename Collection>
string Join(const Collection& c, const string& d) {
  stringstream ss;
  bool isFirst = true;
  for (const auto& i : c) {
    if (!isFirst) {
      ss << d;
    }
    isFirst = false;
    ss << i;
  }
  return ss.str();
}
template<typename F, typename S>
ostream& operator<<(ostream& out, const pair<F, S>& p) {
  return out << p.first << ": " << p.second;
}
template<typename K, typename V>
ostream& operator<<(ostream& out, const map<K, V>& m) {
  return out << '{' << Join(m, ", ") << '}';
}
template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  return out << '[' << Join(v, ", ") << ']';
}
int main() {
  TeamTasks tasks;
  while (cin) {
    string command, person;
    int num;
    cin >> command >> person;
    if (command == "AddNewTasks") {
      cin >> num;
      while (num--) tasks.AddNewTask(person);
      cout << "[]" << endl;
    } else if (command == "PerformPersonTasks") {
      cin >> num;
      TasksInfo updated_tasks, untouched_tasks;
      tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks(person, num);
      cout << vector<TasksInfo>{updated_tasks, untouched_tasks} << endl;
    } else if (command == "GetPersonTasksInfo") {
      cout << tasks.GetPersonTasksInfo(person) << endl;
    } else if (command.size() && command[0] != '#') {
      throw invalid_argument("wrong command: " + command);
    }
  }
}
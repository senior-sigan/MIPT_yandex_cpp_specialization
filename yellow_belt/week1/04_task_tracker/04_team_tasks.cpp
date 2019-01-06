/**
 * Реализуйте класс TeamTasks, позволяющий хранить статистику по статусам задач команды разработчиков.
 *
 * Метод PerformPersonTasks должен реализовывать следующий алгоритм:
 *
 * 1. Рассмотрим все не выполненные задачи разработчика person.
 * 2. Упорядочим их по статусам: сначала все задачи в статусе NEW, затем все задачи в статусе IN_PROGRESS и, наконец,
 * задачи в статусе TESTING. 3, Рассмотрим первые task_count задач и переведём каждую из них в следующий статус в
 * соответствии с естественным порядком: NEW → IN_PROGRESS → TESTING → DONE.
 * 4. Вернём кортеж из двух элементов: информацию о статусах обновившихся задач (включая те, которые оказались в статусе
 * DONE) и информацию о статусах остальных не выполненных задач.
 *
 * Гарантируется, что task_count является положительным числом. Если task_count превышает текущее количество
 * невыполненных задач разработчика, достаточно считать, что task_count равен количеству невыполненных задач: дважды
 * обновлять статус какой-либо задачи в этом случае не нужно.
 *
 * Кроме того, гарантируется, что метод GetPersonTasksInfo не будет вызван для разработчика, не имеющего задач.
 *
 * Пример работы метода PerformPersonTasks
 * Предположим, что у конкретного разработчика имеется 10 задач со следующими статусами:
 *
 * - NEW — 3
 * - IN_PROGRESS — 2
 * - TESTING — 4
 * - DONE — 1
 *
 * Поступает команда PerformPersonTasks с параметром task_count = 4, что означает обновление статуса для 3 задач c NEW
 * до IN_PROGRESS и для 1 задачи с IN_PROGRESS до TESTING. Таким образом, новые статусы задач будут следующими:
 *
 * - IN_PROGRESS — 3 обновлённых, 1 старая
 * - TESTING — 1 обновлённая, 4 старых
 * - DONE — 1 старая
 *
 * В этом случае необходимо вернуть кортеж из 2 словарей:
 *
 * - Обновлённые задачи: IN_PROGRESS — 3, TESTING — 1.
 * - Не обновлённые задачи, исключая выполненные: IN_PROGRESS — 1, TESTING — 4.
 *
 * Словари не должны содержать лишних элементов, то есть статусов, которым соответствует ноль задач.
 *
 * Примечание
 * Обновление словаря одновременно с итерированием по нему может привести к непредсказуемым последствиям. При
 * возникновении такой необходимости рекомендуется сначала в отдельном временном словаре собрать информацию об
 * обновлениях, а затем применить их к основному словарю.
 *
 * Вывод:
 * ```
 * Ilia's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
 * Ivan's tasks: 3 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
 * Updated Ivan's tasks: 0 new tasks, 2 tasks in progress, 0 tasks are being tested, 0 tasks are done
 * Untouched Ivan's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
 * Updated Ivan's tasks: 0 new tasks, 1 tasks in progress, 1 tasks are being tested, 0 tasks are done
 * Untouched Ivan's tasks: 0 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done
 * ```
 */

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

using namespace std;

// Перечислимый тип для статуса задачи
// enum class TaskStatus {
//   NEW,          // новая
//   IN_PROGRESS,  // в разработке
//   TESTING,      // на тестировании
//   DONE          // завершена
// };

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
// using TasksInfo = map<TaskStatus, int>;

TaskStatus next_status(const TaskStatus& status) {
  auto ret = static_cast<TaskStatus>(static_cast<int>(status) + 1);
  return ret;
}

class TeamTasks {
 private:
  map<string, TasksInfo> db;
  const TasksInfo EMPTY = {};

 public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const {
    if (db.count(person) == 0) return EMPTY;
    return db.at(person);
  }

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person) {
    db[person][TaskStatus::NEW]++;
  }

  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
    if (db.count(person) == 0) return {};

    TasksInfo upd;
    set<TaskStatus> to_delete;

    // calculate updates
    for (auto& kv : db.at(person)) {
      if (kv.first == TaskStatus::DONE) continue;
      if (kv.second > 0) {
        auto delta = min(task_count, kv.second);
        kv.second -= delta;
        if (kv.second == 0) {
          to_delete.insert(kv.first);
        }
        task_count -= delta;
        upd[next_status(kv.first)] += delta;
      }
      if (task_count <= 0) break;
    }

    TasksInfo old;
    for (const auto& kv : db.at(person)) {
      if (kv.first == TaskStatus::DONE) continue;
      if (kv.second != 0) {
        old[kv.first] = kv.second;
      }
    }

    for (const auto& k : to_delete) {
      db.at(person).erase(k);
    }

    for (const auto& kv : upd) {
      db.at(person)[kv.first] += kv.second;
    }
    return make_tuple(upd, old);
  }
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
// void PrintTasksInfo(TasksInfo tasks_info) {
//   cout << tasks_info[TaskStatus::NEW] << " new tasks"
//        << ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress"
//        << ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested"
//        << ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
// }

// void test_0() {
//   TeamTasks tasks;
//   tasks.AddNewTask("Ilia");
//   for (int i = 0; i < 3; ++i) {
//     tasks.AddNewTask("Ivan");
//   }
//   cout << "Ilia's tasks: ";
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
//   cout << "Ivan's tasks: ";
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

//   TasksInfo updated_tasks, untouched_tasks;

//   tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
//   cout << "Updated Ivan's tasks: ";
//   PrintTasksInfo(updated_tasks);
//   cout << "Untouched Ivan's tasks: ";
//   PrintTasksInfo(untouched_tasks);

//   tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
//   cout << "Updated Ivan's tasks: ";
//   PrintTasksInfo(updated_tasks);
//   cout << "Untouched Ivan's tasks: ";
//   PrintTasksInfo(untouched_tasks);
// }

// void test_1() {
//   TeamTasks tasks;
//   for (int i = 0; i < 5; ++i) {
//     tasks.AddNewTask("Alice");
//   }
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//   tasks.PerformPersonTasks("Alice", 5);
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//   tasks.PerformPersonTasks("Alice", 5);
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//   tasks.PerformPersonTasks("Alice", 1);
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//   for (int i = 0; i < 5; ++i) {
//     tasks.AddNewTask("Alice");
//   }
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//   tasks.PerformPersonTasks("Alice", 2);
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//   tasks.PerformPersonTasks("Alice", 4);
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
// }

// int main() {
//   test_1();
//   return 0;
// }
/**
 * Напишите функцию BuildMapValuesSet, принимающую на вход словарь map<int, string>
 * и возвращающую множество значений этого словаря.
 **/

#include <map>
#include <set>
#include <string>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
  set<string> values;
  for (const auto& item : m) {
    values.insert(item.second);
  }
  return values;
}
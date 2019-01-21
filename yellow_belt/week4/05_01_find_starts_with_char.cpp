/**
Напишите функцию FindStartsWith:

- принимающую отсортированный набор строк в виде итераторов range_begin, range_end и один символ prefix;
- возвращающую диапазон строк, начинающихся с символа prefix, в виде пары итераторов.

Если итоговый диапазон пуст, его границы должны указывать на то место в контейнере, куда можно без нарушения порядка
сортировки вставить любую строку, начинающуюся с символа prefix (подобно алгоритму equal_range). Гарантируется, что
строки состоят лишь из строчных латинских букв и символ prefix также является строчной латинской буквой.

Поиск должен осуществляться за логарифмическую сложность — например, с помощью двоичного поиска.
*/

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct Comp {
  bool operator()(const string& str, const char& c) {
    return str[0] < c;
  }
  bool operator()(const char& c, const string& str) {
    return str[0] > c;
  }
};

template<typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {
  return equal_range(range_begin, range_end, prefix, Comp{});
}

int main() {
  /**
   * moscow murmansk
   * 2 2
   * 3 3
   */
  const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

  const auto m_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
  for (auto it = m_result.first; it != m_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  const auto p_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
  cout << (p_result.first - begin(sorted_strings)) << " " << (p_result.second - begin(sorted_strings)) << endl;

  const auto z_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
  cout << (z_result.first - begin(sorted_strings)) << " " << (z_result.second - begin(sorted_strings)) << endl;

  return 0;
}
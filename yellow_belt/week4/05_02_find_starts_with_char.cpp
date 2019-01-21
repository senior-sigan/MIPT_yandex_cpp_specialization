/**
Напишите более универсальный вариант функции FindStartsWith, принимающий в качестве префикса произвольную строку,
состоящую из строчных латинских букв.

*/

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

template<typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix) {
  string nx = prefix;
  ++nx[nx.size() - 1];

  auto lwr = lower_bound(range_begin, range_end, prefix);
  auto upr = lower_bound(range_begin, range_end, nx);

  return make_pair(lwr, upr);
}

int main() {
  /**
   * moscow motovilikha
   * 2 2
   * 3 3
   */

  const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

  const auto mo_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  const auto mt_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
  cout << (mt_result.first - begin(sorted_strings)) << " " << (mt_result.second - begin(sorted_strings)) << endl;

  const auto na_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " " << (na_result.second - begin(sorted_strings)) << endl;

  return 0;
}

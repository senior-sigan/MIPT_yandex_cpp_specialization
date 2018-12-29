/**
 * В стандартном потоке даны три строки, разделённые пробелом.
 * Каждая строка состоит из строчных латинских букв и имеет длину не более 30 символов.
 * Выведите в стандартный вывод лексикографически минимальную из них.
 **/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  vector<string> s(3);
  cin >> s[0] >> s[1] >> s[2];
  sort(s.begin(), s.end());
  cout << s[0];
  return 0;
}

/**
 * Напишите функцию SplitIntoWords, разбивающую строку на слова по пробелам.
 * Гарантируется, что:
 * - строка непуста;
 * - строка состоит лишь из латинских букв и пробелов;
 * - первый и последний символы строки не являются пробелами;
 * - строка не содержит двух пробелов подряд.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
  if (s.empty()) return {};
  vector<string> res;
  auto cur = begin(s);

  while (true) {
    auto next = find(cur, end(s), ' ');
    auto chunk = string(cur, next);
    res.push_back(chunk);
    if (next == end(s)) break;
    cur = next + 1;
  };
  return res;
}

// int main() {
//   string s = "C Cpp Java Python";

//   vector<string> words = SplitIntoWords(s);
//   cout << words.size() << " ";
//   for (auto it = begin(words); it != end(words); ++it) {
//     if (it != begin(words)) {
//       cout << "/";
//     }
//     cout << *it;
//   }
//   cout << endl;

//   return 0;
// }

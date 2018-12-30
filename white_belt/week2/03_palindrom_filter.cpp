/**
 * Напишите функцию, которая
 * - называется PalindromFilter
 * - возвращает vector<string>
 * - принимает vector<string> words и int minLength
 * - возвращает все строки из вектора words, которые являются палиндромами и имеют длину не меньше minLength
 *
 * Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.
 **/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string str) {
  if (str.size() < 2) return true;
  if (str[0] != str[str.size() - 1]) return false;
  return IsPalindrom(str.substr(1, str.size() - 2));
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
  vector<string> result;
  copy_if(words.begin(), words.end(), back_inserter(result),
          [minLength](string word) { return word.size() >= minLength && IsPalindrom(word); });
  return result;
}

int main(int argc, char const *argv[]) {
  vector<string> words = {"weew", "bro", "code", "abacaba", "aba"};
  int minLength = 4;
  for (auto w : PalindromFilter(words, minLength)) {
    cout << w << " ";
  }
  cout << endl;
  return 0;
}

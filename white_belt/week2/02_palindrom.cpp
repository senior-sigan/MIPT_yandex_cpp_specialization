/**
 * Напишите функцию, которая
 * - называется IsPalindrom
 * - возвращает bool
 * - принимает параметр типа string и возвращает, является ли переданная строка палиндромом
 * Палиндром - это слово или фраза, которые одинаково читаются слева направо и справа налево.
 * Пустая строка является палиндромом.
 **/
#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string str) {
  if (str.size() < 2) return true;
  if (str[0] != str[str.size() - 1]) return false;
  return IsPalindrom(str.substr(1, str.size() - 2));
}

int main(int argc, char const *argv[]) {
  cout << IsPalindrom("madam") << endl;
  cout << IsPalindrom("gentleman") << endl;
  cout << IsPalindrom("X") << endl;

  return 0;
}

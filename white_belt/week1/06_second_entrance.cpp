/**
 * Дана строка.
 * Найдите в этой строке второе вхождение буквы f и выведите индекс этого вхождения.
 * Если буква f в данной строке встречается только один раз, выведите число -1,
 * а если не встречается ни разу, выведите число -2. Индексы нумеруются с нуля.
 **/
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  int c = 0;
  int index = 0;
  string str;
  cin >> str;
  for (auto i = 0; i < str.size(); i++) {
    if (str[i] == 'f') {
      c++;
      index = i;
    }
    if (c == 2) {
      cout << index;
      return 0;
    }
  }

  if (c == 0) {
    cout << -2;
  } else if (c == 1) {
    cout << -1;
  }

  return 0;
}

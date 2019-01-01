/**
Два слова называются синонимами друг друга, если они имеют похожие значения.
Реализуйте следующие операции над словарём синонимов:

- ADD word1 word2 — добавить в словарь пару синонимов (word1, word2).
- COUNT word — узнать количество синонимов слова word.
- CHECK word1 word2 — проверить, являются ли слова word1 и word2 синонимами.
  Слова word1 и word2 считаются синонимами,
  если среди запросов ADD был хотя бы один запрос ADD word1 word2 или ADD word2 word1.

Формат ввода
Сначала вводится количество запросов Q, затем Q строк с описаниями запросов.
Гарантируется, что в каждом запросе CHECK и ADD слова word1 и word2 различны.
Все слова состоят лишь из латинских букв, цифр и символов подчёркивания.

Формат вывода
Для каждого запроса в соответствующей строке выведите ответ на него:

В ответ на запрос COUNT word выведите единственное целое число — количество синонимов слова word.
В ответ на запрос CHECK word1 word2 выведите строку YES,
если word1 и word2 являются синонимами, и NO в противномслучае.

Пример
Ввод
```
8
ADD program code
COUNT cipher
ADD code cipher
COUNT code
COUNT program
CHECK code program
CHECK program cipher
CHECK cpp java
```

Вывод
```
0
2
1
YES
NO
NO
```
**/

#include <iostream>
#include <map>
#include <set>

using namespace std;

class Synonymus {
  map<string, set<string>> words;

 public:
  void add(string word1, string word2) {
    words[word1].insert(word2);
    words[word2].insert(word1);
  }
  void count(string word) {
    cout << words[word].size() << endl;
  }
  void check(string word1, string word2) {
    if (words[word1].count(word2) != 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
};

void handle(Synonymus& synonymus) {
  string op;
  cin >> op;
  if (op == "ADD") {
    string word1, word2;
    cin >> word1 >> word2;
    synonymus.add(word1, word2);
  } else if (op == "COUNT") {
    string word;
    cin >> word;
    synonymus.count(word);
  } else if (op == "CHECK") {
    string word1, word2;
    cin >> word1 >> word2;
    synonymus.check(word1, word2);
  }
}

int main(int argc, char const* argv[]) {
  Synonymus synonymus;
  int q;
  cin >> q;
  for (; q > 0; q--) {
    handle(synonymus);
  }
  return 0;
}

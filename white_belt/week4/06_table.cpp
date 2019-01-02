/**
 * В первой строке файла input.txt записаны два числа N и M.
 * Далее в файле находится таблица из N строк и M столбцов, представленная в формате CSV (comma-separated values).
 * Такой формат часто используется для текстового представления таблиц с данными:
 * в файле несколько строк, значения из разных ячеек внутри строки отделены друг от друга запятыми.
 * Ваша задача — вывести данные на экран в виде таблицы, размер ячейки которой равен 10, соседние ячейки отделены друг
 *от друга пробелом. После последней ячейки пробела быть не должно. Гарантируется, что в таблице будет ровно N строк и M
 * столбцов, значение каждой из ячеек — целое число.
 **/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream input("input.txt");
  if (!input) return -1;
  int n, m;
  input >> n;
  input.ignore(1);
  input >> m;
  input.ignore(1);
  while (--n > -1) {
    for (int i = 0; i < m; i++) {
      string str;
      if (i == m - 1) {
        getline(input, str);
        cout << setw(10) << right << str;
      } else {
        getline(input, str, ',');
        cout << setw(10) << right << str << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
/**
Напишите шаблонную функцию MergeSort, принимающую два итератора шаблонного типа RandomIt и сортирующую заданный ими
диапазон с помощью сортировки слиянием. Гарантируется, что:
- итераторы типа RandomIt аналогичны по функциональности итераторам вектора и строки, то есть их можно сравнивать с
помощью операторов <, <=, > и >=, а также вычитать и складывать с числами;
- сортируемые объекты можно сравнивать с помощью оператора <.

Часть 2. Реализация с разбиением на 3 части
Реализуйте сортировку слиянием, разбивая диапазон на 3 равные части, а не на 2. Гарантируется, что длина исходного
диапазона является степенью 3.

Соответственно, пункты 3–5 алгоритма нужно заменить следующими:

Разбить вектор на 3 равные части.
Вызвать функцию MergeSort от каждой части вектора.
Слить первые две трети вектора с помощью алгоритма merge, сохранив результат во временный вектор с помощью
back_inserter. Слить временный вектор из предыдущего пункта с последней третью вектора из п. 2, записав полученный
отсортированный диапазон вместо исходного.
*/

#include <iostream>
#include <vector>

using namespace std;

template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  if (range_end - range_begin < 2) return;
  vector<typename RandomIt::value_type> elements(range_begin, range_end);
  auto size = elements.size() / 3;
  auto f1 = begin(elements);
  auto l1 = f1 + size;
  auto f2 = l1;
  auto l2 = f2 + size;
  auto f3 = l2;
  auto l3 = f3 + size;
  MergeSort(f1, l1);
  MergeSort(f2, l2);
  MergeSort(f3, l3);
  vector<typename RandomIt::value_type> m;
  merge(f1, l1, f2, l2, back_inserter(m));
  merge(begin(m), end(m), f3, l3, range_begin);
}
int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

/**
 * Напишите шаблонную функцию FindGreaterElements, принимающую множество elements объектов типа T и ещё один объект
 * border типа T и возвращающую вектор из всех элементов множества, бо́льших border, в возрастающем порядке.
 */
template<typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
  auto from = find_if(elements.begin(), elements.end(), [border](const T& el) { return el > border; });
  vector<T> res(from, elements.end());
  return res;
}

int main() {
  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
    cout << x << " ";
  }
  cout << endl;

  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}

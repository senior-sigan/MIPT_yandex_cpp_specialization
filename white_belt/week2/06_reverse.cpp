/**
 * Реализуйте функцию void Reverse(vector<int>& v),
 * которая переставляет элементы вектора в обратном порядке.
 **/

#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
  if (v.size() < 2) return;  // nothing to do
  for (int i = 0; i < v.size() / 2; i++) {
    auto tmp = v[v.size() - i - 1];
    v[v.size() - i - 1] = v[i];
    v[i] = tmp;
  }
}

int main(int argc, char const* argv[]) {
  vector<int> numbers = {1, 5, 3, 4, 2, 9};
  Reverse(numbers);
  for (auto n : numbers) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}

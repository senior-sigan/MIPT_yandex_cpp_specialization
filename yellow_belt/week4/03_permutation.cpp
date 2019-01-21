/**
 * Дано целое положительное число N, не превышающее 9. Выведите все перестановки чисел от 1 до N в обратном
 * лексикографическом порядке (см. пример).
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> ar(n);
  for (int i = 0; i < n; i++) {
    ar[i] = n - i;
  }
  do {
    for (int i = 0; i < n; i++) {
      cout << ar[i];
      if (i != n - 1) {
        cout << " ";
      }
    }
    cout << endl;
  } while (prev_permutation(begin(ar), end(ar)));
  return 0;
}

/**
 * В стандартном потоке дана одна строка, состоящая из N + 1 целых чисел.
 * Первым числом идёт само число N. Далее следуют ещё N чисел, обозначим их за массив A.
 * Между собой числа разделены пробелом.
 * Отсортируйте массив А по модулю и выведите его в стандартный поток.
 **/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const* argv[]) {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (auto& num : nums) {
    cin >> num;
  }
  sort(begin(nums), end(nums), [](const int& a, const int& b) { return abs(a) < abs(b); });
  int i = 0;
  for (auto num : nums) {
    cout << num;
    if (++i <= nums.size() - 1) {
      cout << " ";
    }
  }
  return 0;
}

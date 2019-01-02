/**
 * В стандартном потоке дана одна строка, состоящая из числа N и следующих за ним N строк S.
 * Между собой число и строки разделены пробелом.
 * Отсортируйте строки S в лексикографическом порядке по возрастанию, игнорируя регистр букв,
 * и выведите их в стандартный поток вывода.
 **/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string lower(const string str) {
  string data = str;
  transform(begin(data), end(data), begin(data), ::tolower);
  return data;
}

int main(int argc, char const* argv[]) {
  int n;
  cin >> n;
  vector<string> nums(n);
  for (auto& num : nums) {
    cin >> num;
  }
  sort(begin(nums), end(nums), [](const string& a, const string& b) { return lower(a) < lower(b); });
  int i = 0;
  for (auto num : nums) {
    cout << num;
    if (++i <= nums.size() - 1) {
      cout << " ";
    }
  }
  return 0;
}

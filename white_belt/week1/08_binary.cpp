/**
 * На вход дано целое положительное число N.
 * Выведите его в двоичной системе счисления без ведущих нулей.
 **/

#include <iostream>

using namespace std;

void print_binary(int n) {
  if (n != 0) {
    print_binary(n >> 1);
  }
  if (n != 0) {
    cout << n % 2;
  }
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  print_binary(n);
  return 0;
}

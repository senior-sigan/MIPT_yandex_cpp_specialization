/**
 * На вход вашей программе в стандартном вводе даны действительные коэффициенты
 * A, B и C уравнения Ax² + Bx + C = 0.
 * Выведите все его различные действительные корни в любом порядке.
 * Гарантируется, что хотя бы один из коэффициентов не равен нулю.
 **/
#include <cmath>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  double a, b, c;
  cin >> a >> b >> c;
  if (a == 0) {
    if (b != 0) cout << -c / b;
  } else {
    double d = b * b - 4 * a * c;
    if (d < 0) {
      // nothing to do
    } else if (d == 0) {
      if (b != 0) {
        double x = -b / (2 * a);
        cout << x;
      } else {
        cout << 0;
      }
    } else {
      double x1 = (-b + sqrt(d)) / (2 * a);
      double x2 = (-b - sqrt(d)) / (2 * a);
      cout << x1 << " " << x2;
    }
  }
  return 0;
}

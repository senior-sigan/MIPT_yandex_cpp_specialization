#include <exception>
#include <iostream>
#include <stdexcept>
using namespace std;

int abs(int a) {
  if (a < 0) return -a;
  return a;
}

int gcd(int a, int b) {
  while (a > 0 && b > 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }

  return a + b;
}

class Rational {
 public:
  Rational() {
    n = 0;
    d = 1;
  }

  Rational(int numerator, int denominator) {
    if (denominator == 0) throw invalid_argument("");

    if (numerator == 0) {
      n = 0;
      d = 1;
      return;
    }

    if (denominator < 0) {
      denominator *= -1;
      numerator *= -1;
    }

    int q = gcd(abs(numerator), abs(denominator));
    n = numerator / q;
    d = denominator / q;
  }

  int Numerator() const {
    return n;
  }

  int Denominator() const {
    return d;
  }

 private:
  int n;
  int d;
};

Rational operator/(const Rational& lhs, const Rational& rhs) {
  if (lhs.Denominator() * rhs.Numerator() == 0) throw domain_error("");
  return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

int main() {
  try {
    Rational r(1, 0);
    cout << "Doesn't throw in case of zero denominator" << endl;
    return 1;
  } catch (invalid_argument&) {
  }

  try {
    Rational(1, 2) / Rational(0, 1);
    cout << "Doesn't throw in case of division by zero " << endl;
    return 2;
  } catch (domain_error&) {
  }

  cout << "OK" << endl;
  return 0;
}

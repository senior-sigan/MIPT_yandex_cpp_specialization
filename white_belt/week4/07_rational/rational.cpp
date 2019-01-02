#include <iostream>
#include <map>
#include <set>
#include <vector>
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

bool operator==(const Rational& lhs, const Rational rhs) {
  return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
  return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
                  lhs.Denominator() * rhs.Denominator());
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
  return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
                  lhs.Denominator() * rhs.Denominator());
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
  return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
  return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

ostream& operator<<(ostream& stream, const Rational& rat) {
  stream << rat.Numerator() << "/" << rat.Denominator();
  return stream;
}

istream& operator>>(istream& stream, Rational& rat) {
  int n;
  int d;
  if (stream.peek() != EOF) {
    stream >> n;
    stream.ignore(1);
  }
  if (stream.peek() != EOF) {
    stream >> d;
    rat = Rational(n, d);
  }
  return stream;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
  int ln = lhs.Numerator() * rhs.Denominator();
  int rn = rhs.Numerator() * lhs.Denominator();
  return ln < rn;
}

int main() {
  {
    const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
    if (rs.size() != 3) {
      cout << "Wrong amount of items in the set" << endl;
      return 1;
    }

    vector<Rational> v;
    for (auto x : rs) {
      v.push_back(x);
    }
    if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
      cout << "Rationals comparison works incorrectly" << endl;
      return 2;
    }
  }

  {
    map<Rational, int> count;
    ++count[{1, 2}];
    ++count[{1, 2}];

    ++count[{2, 3}];

    if (count.size() != 2) {
      cout << "Wrong amount of items in the map" << endl;
      return 3;
    }
  }

  cout << "OK" << endl;
  return 0;
}

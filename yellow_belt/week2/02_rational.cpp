/**
 * Список требований, предъявляемых к реализации интерфейса класса Rational:
 *
 * Конструктор по умолчанию должен создавать дробь с числителем 0 и знаменателем 1.
 * При конструировании объекта класса Rational с параметрами p и q должно выполняться сокращение дроби p/q.
 * Если дробь p/q отрицательная, то объект Rational(p, q) должен иметь отрицательный числитель и положительный
 * знаменатель. Если дробь p/q положительная, то объект Rational(p, q) должен иметь положительные числитель и
 * знаменатель (обратите внимание на случай Rational(-2, -3)). Если числитель дроби равен нулю, то знаменатель должен
 * быть равен 1. Разработайте набор юнит-тестов, которые будут проверять корректность реализации класса Rational.
 * Тестировать случай, когда знаменатель равен нулю, не надо.
 */

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template<class T>
ostream& operator<<(ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template<class T>
ostream& operator<<(ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template<class K, class V>
ostream& operator<<(ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
 public:
  template<class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

 private:
  int fail_count = 0;
};

// Should be commented when make a submission
#include "rational.cpp"

void TestDefaultConstructor() {
  auto rat = Rational();
  AssertEqual(rat.Denominator(), 1);
  AssertEqual(rat.Numerator(), 0);
}

void TestZeroNumerator() {
  auto rat = Rational(0, 2);
  AssertEqual(rat.Numerator(), 0);
  AssertEqual(rat.Denominator(), 1);
}

void TestZeroNumeratorConstructor() {
  auto rat = Rational(0, 100500);
  AssertEqual(rat.Numerator(), 0);
  AssertEqual(rat.Denominator(), 1);
}

void TestReduction() {
  {
    auto rat = Rational(2, 4);
    AssertEqual(rat.Numerator(), 1);
    AssertEqual(rat.Denominator(), 2);
  }
  {
    auto rat = Rational(27, 81);
    AssertEqual(rat.Numerator(), 1);
    AssertEqual(rat.Denominator(), 3);
  }
  {
    auto rat = Rational(3, 11);
    AssertEqual(rat.Numerator(), 3);
    AssertEqual(rat.Denominator(), 11);
  }
}

void TestNegative() {
  {
    auto rat = Rational(-3, 11);
    AssertEqual(rat.Numerator(), -3);
    AssertEqual(rat.Denominator(), 11);
  }
  {
    auto rat = Rational(3, -11);
    AssertEqual(rat.Numerator(), -3);
    AssertEqual(rat.Denominator(), 11);
  }
}

void TestNegativeReduction() {
  {
    auto rat = Rational(-3, -11);
    AssertEqual(rat.Numerator(), 3);
    AssertEqual(rat.Denominator(), 11);
  }
}

int main() {
  TestRunner runner;
  runner.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
  runner.RunTest(TestZeroNumerator, "TestZeroNumerator");
  runner.RunTest(TestZeroNumeratorConstructor, "TestZeroNumeratorConstructor");
  runner.RunTest(TestReduction, "TestReduction");
  runner.RunTest(TestNegativeReduction, "TestNegativeReduction");
  runner.RunTest(TestNegative, "TestNegative");
  return 0;
}

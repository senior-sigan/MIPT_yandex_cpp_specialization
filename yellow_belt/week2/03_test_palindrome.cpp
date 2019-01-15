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

bool IsPalindrom(string str) {
  if (str.size() < 2) return true;
  if (str[0] != str[str.size() - 1]) return false;
  return IsPalindrom(str.substr(1, str.size() - 2));
}

void TestEmptyString() {
  Assert(IsPalindrom(""), "empty string is palindrom");
}

void TestSimpleCases() {
  Assert(IsPalindrom(""), "'' is palindrom");
  Assert(IsPalindrom("a"), "'a' is palindrom");
  Assert(IsPalindrom("aba"), "aba is palindrom");
  Assert(!IsPalindrom("abab"), "abab is not palindrom");
  Assert(IsPalindrom("ababa"), "ababa is palindrom");
  Assert(!IsPalindrom("abc"), "abc is not palindrom");
  Assert(!IsPalindrom("aaac"), "aaac is not palindrom");
}

void TestSpaces() {
  Assert(!IsPalindrom("b ob b"), "b ob b is not palindrom");
  Assert(IsPalindrom("   "), "'   ' is palindrom");
  Assert(IsPalindrom(" a "), "' a ' is palindrom");
  Assert(!IsPalindrom(" a"), "' a' is not palindrom");
  Assert(!IsPalindrom(" a  "), "' a  ' is not palindrom");
  Assert(!IsPalindrom("ab  ba "), "'ab  ba ' is not palindrom");
}

void TestStrange() {
  Assert(!IsPalindrom("cba"), "'cba' is not palindrom");
  Assert(!IsPalindrom("abcvba"), "'abcvba' is not palindrom");
  Assert(!IsPalindrom("aBaba"), "aBaba is not palindrom");
  Assert(!IsPalindrom("baobab"), "baobab is not palindrom");
  Assert(!IsPalindrom("babcb"), "babcb is not palindrom");
  Assert(!IsPalindrom("babac"), "babac is not palindrom");
  Assert(!IsPalindrom("kek\n"), "kek\\n is not palindrom");
  Assert(!IsPalindrom("was it a car or a cat i saw"), "because space not match");
}

void TestAll() {
  Assert(IsPalindrom("a s d s a"), "Palindrom with whitespaces.");
  Assert(!IsPalindrom("a sd s a"), "Not Palindrom with whitespaces.");
  Assert(!IsPalindrom(" sds"), "Not Palindrom1.");
  Assert(!IsPalindrom("qweew"), "Not Palindrom2.");
  Assert(!IsPalindrom(" qweq "), "Not Palindrom3.");
  Assert(!IsPalindrom(" qwe wq "), "Not Palindrom3.");
  Assert(!IsPalindrom(" qw ewq "), "Not Palindrom3.");
  Assert(IsPalindrom("qweewq"), "Palindrom1.");
  Assert(IsPalindrom(" asdfdsa "), "Palindrom3.");
  Assert(IsPalindrom(" asdffdsa "), "Palindrom3.");

  Assert(IsPalindrom("madam"), "argh!!!");
  Assert(IsPalindrom("lool"), "argh!!!");
  Assert(IsPalindrom("o"), "argh!!!");
  Assert(IsPalindrom("top pot"), "argh!!!");
  Assert(IsPalindrom("o lol o"), "argh!!!");
  Assert(!IsPalindrom("olo lo"), "argh!!!");
  Assert(!IsPalindrom("ol olo"), "argh!!!");
  Assert(!IsPalindrom(" lolo"), "argh!!!");
  Assert(!IsPalindrom("olol "), "argh!!!");
  Assert(IsPalindrom(" olo "), "argh!!!");
  Assert(!IsPalindrom("olol"), "argh!!!");
  Assert(!IsPalindrom("motor"), "argh!!!");
  Assert(!IsPalindrom("topo gun"), "argh!!!");
  Assert(!IsPalindrom("olol "), "argh!!!");
  Assert(!IsPalindrom(" lol"), "argh!!!");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestEmptyString, "TestEmptyString");
  runner.RunTest(TestSimpleCases, "TestSimpleCases");
  runner.RunTest(TestSpaces, "TestSpaces");
  runner.RunTest(TestStrange, "TestStrange");
  runner.RunTest(TestAll, "TestAll");
  return 0;
}

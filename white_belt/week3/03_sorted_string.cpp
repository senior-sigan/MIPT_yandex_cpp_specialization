/**
 * Реализуйте класс, поддерживающий набор строк в отсортированном порядке.
 **/
#include <string>
#include <vector>

using namespace std;

class SortedStrings {
 public:
  void AddString(const string& s) {
    data.push_back(s);
  }
  vector<string> GetSortedStrings() {
    sort(begin(data), end(data));
    return data;
  }

 private:
  vector<string> data;
};
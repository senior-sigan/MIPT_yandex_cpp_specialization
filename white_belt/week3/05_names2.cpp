/**
 * Дополните класс из предыдущей задачи «Имена и фамилии — 1» методом GetFullNameWithHistory
 * В отличие от метода GetFullName, метод GetFullNameWithHistory должен вернуть не только последние имя и фамилию к
 * концу данного года, но ещё и все предыдущие имена и фамилии в обратном хронологическом порядке. Если текущие факты
 * говорят о том, что человек два раза подряд изменил фамилию или имя на одно и то же, второе изменение при формировании
 * истории нужно игнорировать.
 * ```
 * int main() {
 *   Person person;
 *
 *   person.ChangeFirstName(1900, "Eugene");
 *   person.ChangeLastName(1900, "Sokolov");
 *   person.ChangeLastName(1910, "Sokolov");
 *   person.ChangeFirstName(1920, "Evgeny");
 *   person.ChangeLastName(1930, "Sokolov");
 *   cout << person.GetFullNameWithHistory(1940) << endl;
 *
 *   return 0;
 * }
 * ```
 *
 * ```
 * Evgeny (Eugene) Sokolov
 * ```
 **/

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Person {
 public:
  void ChangeFirstName(int year, const string& first_name) {
    names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    surnames[year] = last_name;
  }
  string GetFullName(int year) {
    string name = find_last(names, year);
    string surname = find_last(surnames, year);

    bool hasName = name.size() != 0;
    bool hasSurname = surname.size() != 0;

    if (!hasName && !hasSurname) {
      return "Incognito";
    }

    if (!hasName && hasSurname) {
      return surname + " with unknown first name";
    }

    if (hasName && !hasSurname) {
      return name + " with unknown last name";
    }

    return name + " " + surname;
  }

  string GetFullNameWithHistory(int year) {
    vector<string> name = find_previous(names, year);
    vector<string> surname = find_previous(surnames, year);

    if (name.empty() && surname.empty()) {
      return "Incognito";
    }

    if (name.empty()) {
      return present_name(surname, "last") + " " + present_name(name, "first");
    }

    return present_name(name, "first") + " " + present_name(surname, "last");
  }

 private:
  map<int, string> names;
  map<int, string> surnames;

  string find_last(const map<int, string>& m, int key) {
    for (auto p = m.rbegin(); p != m.rend(); p++) {
      if (p->first <= key) {
        return p->second;
      }
    }
    return "";
  }

  vector<string> find_previous(const map<int, string>& m, int key) {
    vector<string> data;

    for (auto p = m.rbegin(); p != m.rend(); p++) {
      if (p->first <= key) {
        if (data.empty() || data.back() != p->second) {
          data.push_back(p->second);
        }
      }
    }

    return data;
  }

  string present_name(const vector<string>& name, string type) {
    if (name.empty()) return "with unknown " + type + " name";
    if (name.size() == 1) return name[0];
    string res = name[0] + " (";
    for (int i = 1; i < name.size(); i++) {
      res += name[i];
      if (i < name.size() - 1) {
        res += ", ";
      }
    }
    res += ")";

    return res;
  }
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}

/**
Дополните класс Person из задачи «Имена и фамилии — 2» конструктором, позволяющим задать имя и фамилию человека при
рождении, а также сам год рождения. Класс не должен иметь конструктора по умолчанию.

При получении на вход года, который меньше года рождения:
- методы GetFullName и GetFullNameWithHistory должны отдавать "No person";
- методы ChangeFirstName и ChangeLastName должны игнорировать запрос.

Кроме того, необходимо объявить константными все методы, которые по сути ими являются.

Пример
```
int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
```

Вывод
```
No person
Polina Sergeeva
Appolinaria (Polina) Sergeeva
Appolinaria (Polina) Ivanova (Sergeeva)
```
**/

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Person {
 public:
  Person(const string& name, const string& surname, int birth) : birth(birth) {
    names[birth] = name;
    surnames[birth] = surname;
  }

  void ChangeFirstName(int year, const string& first_name) {
    if (year < birth) return;
    names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    if (year < birth) return;
    surnames[year] = last_name;
  }
  string GetFullName(int year) const {
    if (year < birth) return "No person";

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

  string GetFullNameWithHistory(int year) const {
    if (year < birth) return "No person";

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
  int birth;

  map<int, string> names;
  map<int, string> surnames;

  Person(){};

  string find_last(const map<int, string>& m, int key) const {
    for (auto p = m.rbegin(); p != m.rend(); p++) {
      if (p->first <= key) {
        return p->second;
      }
    }
    return "";
  }

  vector<string> find_previous(const map<int, string>& m, int key) const {
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

  string present_name(const vector<string>& name, string type) const {
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
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
/**
 * Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.
 *
 * Cчитайте, что в каждый год может произойти не более одного изменения фамилии и не более одного изменения имени. При
 * этом с течением времени могут открываться всё новые факты из прошлого человека, поэтому года́ в последовательных
 * вызовах методов ChangeLastName и ChangeFirstName не обязаны возрастать.
 *
 * Гарантируется, что все имена и фамилии непусты.
 *
 * Строка, возвращаемая методом GetFullName, должна содержать разделённые одним пробелом имя и фамилию человека по
 * состоянию на конец данного года.
 *
 * Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".
 * Если к данному году случилось изменение фамилии, но не было ни одного изменения имени, верните "last_name with
 * unknown first name". Если к данному году случилось изменение имени, но не было ни одного изменения фамилии, верните
 * "first_name with unknown last name".
 *
 * Пример
 * ```
 * int main() {
 *   Person person;
 *
 *   person.ChangeFirstName(1965, "Polina");
 *   person.ChangeLastName(1967, "Sergeeva");
 *   for (int year : {1900, 1965, 1990}) {
 *     cout << person.GetFullName(year) << endl;
 *   }
 *
 *   person.ChangeFirstName(1970, "Appolinaria");
 *   for (int year : {1969, 1970}) {
 *     cout << person.GetFullName(year) << endl;
 *   }
 *
 *   person.ChangeLastName(1968, "Volkova");
 *   for (int year : {1969, 1970}) {
 *     cout << person.GetFullName(year) << endl;
 *   }
 *
 *   return 0;
 * }
 * ```
 *
 * Вывод
 * ```
 * Incognito
 * Polina with unknown last name
 * Polina Sergeeva
 * Polina Sergeeva
 * Appolinaria Sergeeva
 * Polina Volkova
 * Appolinaria Volkova
 * ```
 **/

#include <iostream>
#include <map>
#include <string>

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
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}

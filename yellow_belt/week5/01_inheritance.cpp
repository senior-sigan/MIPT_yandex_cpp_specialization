/**
 * Определите до конца тела классов, соблюдая следующие требования:
 *
 * 1. Класс Dog должен являться наследником класса Animal.
 * 2. Конструктор класса Dog должен принимать параметр типа string и инициализировать им поле Name в классе Animal.
 */

#include <iostream>
#include <string>

using namespace std;

class Animal {
 public:
  Animal(const string& str) : Name(str) {}

  const string Name;
};

class Dog : public Animal {
 public:
  Dog(const string& str) : Animal(str) {}

  void Bark() {
    cout << Name << " barks: woof!" << endl;
  }
};

// int main() {
//   Dog d("LOL");
//   d.Bark();
// }
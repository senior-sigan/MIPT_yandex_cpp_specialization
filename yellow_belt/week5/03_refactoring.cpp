#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Regarding const methods.
 * In the current task we have all the methods actually consts becouse they just writes to cout.
 * I understand sometime they could become non-const, but who knows :)
 */

/**
 * Every person has a name and profession.
 * Sometime person may change the name and profession, se we keep it non-const, but private.
 * Thats why the Getters are used instead of public const values.
 *
 * Also every Person has ability to Walk. It's default ability, but somebody can override it.
 */
class Person {
  string name;
  string profession;

 public:
  Person(const string& name, const string& profession) : name(name), profession(profession) {}
  const string& GetName() const {
    return name;
  }
  const string& GetType() const {
    return profession;
  }
  virtual void Walk(const string& destination) const {
    cout << GetType() << ": " << GetName() << " walks to: " << destination << endl;
  }
};

class Student : public Person {
  string favouriteSong;

 public:
  Student(const string& name, const string& favouriteSong) : Person(name, "Student"), favouriteSong(favouriteSong) {}

  void Walk(const string& destination) const override {
    Person::Walk(destination);  // Use default Person ability to Walk
    SingSong();                 // and add some feature
  }

  void Learn() const {
    cout << "Student: " << GetName() << " learns" << endl;
  }

  void SingSong() const {
    cout << "Student: " << GetName() << " sings a song: " << GetFavouriteSong() << endl;
  }

  const string& GetFavouriteSong() const {
    return favouriteSong;
  }
};

class Teacher : public Person {
  string subject;

 public:
  Teacher(const string& name, const string& subject) : Person(name, "Teacher"), subject(subject) {}

  void Teach() const {
    cout << "Teacher: " << GetName() << " teaches: " << GetSubject() << endl;
  }

  const string& GetSubject() const {
    return subject;
  }
};

class Policeman : public Person {
 public:
  Policeman(const string& name) : Person(name, "Policeman") {}

  void Check(const Person& p) const {
    cout << "Policeman: " << GetName() << " checks " << p.GetType() << ". " << p.GetType()
         << "'s name is: " << p.GetName() << endl;
  }
};

void VisitPlaces(const Person& person, const vector<string>& places) {
  for (const auto& place : places) {
    person.Walk(place);
  }
}

int main() {
  Teacher t("Jim", "Math");
  Student s("Ann", "We will rock you");
  Policeman p("Bob");

  VisitPlaces(t, {"Moscow", "London"});
  p.Check(s);
  VisitPlaces(s, {"Moscow", "London"});
  t.Teach();
  s.Learn();
  return 0;
}
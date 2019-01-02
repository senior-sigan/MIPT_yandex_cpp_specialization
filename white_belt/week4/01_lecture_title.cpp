/**
 * Допишите конструктор и структуры Specialization, Course, Week так,
 * чтобы объект LectureTitle можно было создать с помощью кода:
 *
 * ```
 * LectureTitle title(
 *     Specialization("C++"),
 *     Course("White belt"),
 *     Week("4th")
 * );
 * ```
 *
 * но нельзя было с помощью следующих фрагментов кода:
 *
 * ```
 * LectureTitle title("C++", "White belt", "4th");
 *
 * LectureTitle title(string("C++"), string("White belt"), string("4th"));
 *
 * LectureTitle title = {"C++", "White belt", "4th"};
 *
 * LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
 *
 * LectureTitle title(
 *     Course("White belt"),
 *     Specialization("C++"),
 *     Week("4th")
 * );
 *
 * LectureTitle title(
 *     Specialization("C++"),
 *     Week("4th"),
 *     Course("White belt")
 * );
 * ```
 **/

#include <string>

using namespace std;

struct Specialization {
  string value;

  explicit Specialization(const string& val) : value(val){};
};

struct Course {
  string value;

  explicit Course(const string& val) : value(val){};
};

struct Week {
  string value;

  explicit Week(const string& val) : value(val){};
};

struct LectureTitle {
  string specialization;
  string course;
  string week;

  explicit LectureTitle(const Specialization& s, const Course& c, const Week& w)
      : specialization(s.value), course(c.value), week(w.value) {}
};

// int main() {
//   LectureTitle title(Specialization("C++"), Course("White belt"), Week("4th"));

//   // should not be compiled

//   LectureTitle title("C++", "White belt", "4th");

//   LectureTitle title(string("C++"), string("White belt"), string("4th"));

//   LectureTitle title = {"C++", "White belt", "4th"};

//   LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};

//   LectureTitle title(Course("White belt"), Specialization("C++"), Week("4th"));

//   LectureTitle title(Specialization("C++"), Week("4th"), Course("White belt"));

//   return 0;
// }
/**
Вам дана функция main, которая считывает из стандартного ввода команды по работе с набором геометрических фигур:

Как видно из кода, есть два вида команд:

- ADD — добавить фигуру в набор;
- PRINT — для каждой фигуры в наборе распечатать название, периметр и площадь.

Программа поддерживает три вида фигур: прямоугольник, треугольник и круг. Их добавление описывается так:

- ADD RECT width height — добавить прямоугольник с размерами width и height (например, ADD RECT 2 3).
- ADD TRIANGLE a b c — добавить треугольник со сторонами a, b и c (например, ADD TRIANGLE 3 4 5).
- ADD CIRCLE r — добавить круг радиуса r (например, ADD CIRCLE 5).

Ввод:
```
ADD RECT 2 3
ADD TRIANGLE 3 4 5
ADD RECT 10 20
ADD CIRCLE 5
PRINT
```
Вывод:
```
RECT 10.000 6.000
TRIANGLE 12.000 6.000
RECT 60.000 200.000
CIRCLE 31.400 78.500
```

Не меняя функцию main, реализуйте недостающие функции и классы:

- базовый класс Figure с чисто виртуальными методами Name, Perimeter и Area;
- классы Triangle, Rect и Circle, которые являются наследниками класса Figure и переопределяют его виртуальные методы;
- функцию CreateFigure, которая в зависимости от содержимого входного потока создаёт shared_ptr<Rect>,
shared_ptr<Triangle> или shared_ptr<Circle>.

Гарантируется, что все команды ADD корректны; размеры всех фигур — это натуральные числа не больше 1000. В качестве
значения π используйте 3,14.
*/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class Figure {
 public:
  virtual string Name() const = 0;
  virtual double Perimeter() const = 0;
  virtual double Area() const = 0;
  virtual ~Figure() {}
};

class Triangle : public Figure {
  int a;
  int b;
  int c;

 public:
  Triangle(int a, int b, int c) : a(a), b(b), c(c) {}
  string Name() const override {
    return "TRIANGLE";
  }
  double Perimeter() const override {
    return a + b + c;
  }
  double Area() const override {
    auto p = Perimeter() / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
  }
};
class Rect : public Figure {
  int width;
  int height;

 public:
  Rect(int width, int height) : width(width), height(height) {}
  string Name() const override {
    return "RECT";
  }
  double Perimeter() const override {
    return (width + height) * 2;
  }
  double Area() const override {
    return width * height;
  }
};
class Circle : public Figure {
  int r;
  double pi = 3.14;

 public:
  Circle(int r) : r(r) {}
  string Name() const override {
    return "CIRCLE";
  }
  double Perimeter() const override {
    return 2.0 * pi * r;
  }
  double Area() const override {
    return pi * r * r;
  }
};

shared_ptr<Figure> CreateFigure(istream& is) {
  string type;
  is >> type;
  if (type == "TRIANGLE") {
    int a, b, c;
    is >> a >> b >> c;
    return make_shared<Triangle>(a, b, c);
  } else if (type == "RECT") {
    int width, height;
    is >> width >> height;
    return make_shared<Rect>(width, height);
  } else if (type == "CIRCLE") {
    int r;
    is >> r;
    return make_shared<Circle>(r);
  }

  throw domain_error("Unsupported operation " + type);
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line);) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3) << current_figure->Name() << " " << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
/**
 * Напишите функцию MoveStrings, которая принимает два вектора строк, source и destination,
 * и дописывает все строки из первого вектора в конец второго.
 * После выполнения функции вектор source должен оказаться пустым.
 **/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
  for (auto str : source) {
    destination.push_back(str);
  }
  source.clear();
}

int main(int argc, char const* argv[]) {
  vector<string> source = {"a", "b", "c"};
  vector<string> destination = {"z"};
  MoveStrings(source, destination);

  for (auto s : source) cout << s << " ";
  cout << endl;
  for (auto s : destination) cout << s << " ";
  cout << endl;
  return 0;
}

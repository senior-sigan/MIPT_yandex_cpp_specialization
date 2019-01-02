#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  ifstream infile("input.txt");

  if (infile) {
    string line;
    while (getline(infile, line)) {
      cout << line << endl;
    }
  }

  return 0;
}
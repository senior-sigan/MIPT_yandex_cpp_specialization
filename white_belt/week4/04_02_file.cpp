#include <fstream>
#include <string>
using namespace std;

int main() {
  ifstream infile("input.txt");
  ofstream outfile("output.txt");

  if (infile && outfile) {
    string line;
    while (getline(infile, line)) {
      outfile << line << endl;
    }
  }

  return 0;
}
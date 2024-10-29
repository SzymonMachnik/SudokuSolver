#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  ifstream inputFile;

  string fileName = "../sudokusToLoadData/1.txt";

  inputFile.open(fileName);

  vector<vector<char>> sudoku;

  if (!inputFile.is_open()) {
    cout << "Can't open" << endl;
  } else {
    string line;

    while (getline(inputFile, line)) {
      vector<char> row;
      for (char c : line) {
        row.push_back(c);
      }
      sudoku.push_back(row);
    }
    inputFile.close();
  }

  for (auto v : sudoku) {
    for (auto c : v) {
      cout << c << " ";
    }
    cout << endl;
  }

  return 0;
}
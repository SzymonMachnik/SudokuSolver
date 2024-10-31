#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  // LOADING SUDOKU FROM DATABASE ////////////////////////
  // ifstream inputFile;

  // string fileName = "../sudokusToLoadData/1.txt";

  // inputFile.open(fileName);

  // vector<vector<char>> sudoku;

  // if (!inputFile.is_open()) {
  //   cout << "Can't open" << endl;
  // } else {
  //   string line;

  //   while (getline(inputFile, line)) {
  //     vector<char> row;
  //     for (char c : line) {
  //       row.push_back(c);
  //     }
  //     sudoku.push_back(row);
  //   }
  //   inputFile.close();
  // }

  // for (auto v : sudoku) {
  //   for (auto c : v) {
  //     cout << c << " ";
  //   }
  //   cout << endl;
  // }

  // CHOOSING RANDOM SUDOKU FROM DATABSE //////////////////

  for (int i = 0; i < 100; i++) {
    const char RANDOMSUDOKUNUMBER = int(1. * rand() / RAND_MAX * 9) + 1 + '0';
    cout << RANDOMSUDOKUNUMBER << endl;
  }

  return 0;
}
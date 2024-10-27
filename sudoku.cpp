#include <iostream>
#include <vector>

using namespace std;

bool isValid(int r, int c, char value, vector<vector<char>>& board) {
  for (int i = 0; i < 9; i++) {
    if (board[i][c] == value) return false;

    if (board[r][i] == value) return false;

    if(board[3*(r/3) + i/3][3*(c/3) + (i%3)] == value)return false;
  }
  return true;
}

void backTrack(vector<vector<char>>& boardOriginal, int r, int c, bool &solved) {
  if (solved) return;
  if (r == 9 && c == 8) {
    solved = true;
    return;
  }
  if (r == 9) {
    r = 0; 
    c++;
  }

  if (boardOriginal[r][c] == '.') {
    for (int i = 1; i < 10; i++) {
        
      if (isValid(r, c, i + '0', boardOriginal)) {
        char value = i + '0';
        boardOriginal[r][c] = value;

        backTrack(boardOriginal, r + 1, c, solved);

        if (solved) return;
        
        boardOriginal[r][c] = '.';
      }

    }
  } else {
    backTrack(boardOriginal, r + 1, c, solved);
  }
  
  return;
}
    
void solveSudoku(vector<vector<char>>& board) {
    bool solved = false;
    backTrack(board, 0, 0, solved);
    return;
}

vector<char> getLineToVectorOfChars(int numberOfLine) {
  vector<char> vline;
  do {
    cout << "Line " << numberOfLine << ": ";
    vline = {};
    string line1;
    cin >> line1;
    for (char c : line1) {
      if ((c >= 49 && c <= 57) || c == '.') {
        vline.push_back(c);
      } else break;
    }
  } while (vline.size() != 9);

  return vline;
}

int main() {
  cout << "SUDOKU SOLVER!" << endl;
  cout << endl;
  cout << "Enter the numbers from sudoku line by line, in case of an empty space use '.'" << endl;

  vector<vector<char>> board = {
    getLineToVectorOfChars(1),
    getLineToVectorOfChars(2),
    getLineToVectorOfChars(3),
    getLineToVectorOfChars(4),
    getLineToVectorOfChars(5),
    getLineToVectorOfChars(6),
    getLineToVectorOfChars(7),
    getLineToVectorOfChars(8),
    getLineToVectorOfChars(9)
  };

  solveSudoku(board);
  cout << "\nSOLUTION: " << endl;
  for (auto v : board) {
    for (auto num : v) {
      cout << num << "  ";
    }
    cout << endl;
  }
}

// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//   vector<vector<char>> board(9, vector<char>(9, '.'));
//   for (auto v : board) {
//     for (auto num : v) {
//       cout << num << " ";
//     }
//     cout << endl;
//   }

//   return 0;
// }
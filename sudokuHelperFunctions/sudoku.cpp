// sudoku.cpp

#include "sudoku.h"

SudokuSolver::SudokuSolver() {
}

// void SudokuSolver::initializeBoard() {
// }

bool SudokuSolver::isValid(int r, int c, char value, std::vector<std::vector<char>>& board) {
  for (int i = 0; i < 9; i++) {
    if (board[i][c] == value) return false;
    if (board[r][i] == value) return false;
    if (board[3 * (r / 3) + i / 3][3 * (c / 3) + (i % 3)] == value) return false;
  }
  return true;
}

void SudokuSolver::backTrack(std::vector<std::vector<char>>& boardOriginal, int r, int c, bool& solved) {
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
}

void SudokuSolver::solveSudoku(std::vector<std::vector<char>>& board) {
  bool solved = false;
  backTrack(board, 0, 0, solved);
  return;
}

void SudokuSolver::InitializeBoard(char (&board)[9][9][2]) {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      board[i][j][0] = '-';
      board[i][j][1] = '\0';
    }
  }
}

void SudokuSolver::resetBoard(char (&board)[9][9][2]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      board[i][j][0] = '-';
      board[i][j][1] = '\0'; 
    }
  }
}

void SudokuSolver::translateSolvedBoardIntoBoardToPrint(char (&boardToPrint)[9][9][2], std::vector<std::vector<char>> &solvedBoard) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      boardToPrint[i][j][0] = solvedBoard[i][j];
      boardToPrint[i][j][1] = '\0'; 
    }
  }
}

void SudokuSolver::translateBoardToPrintIntoBoardToSolve(char (&boardToPrint)[9][9][2], std::vector<std::vector<char>> &boardToSolve, bool &correctSudoku) {
  for (int i = 0; i < 9; i++) {
    std::vector<char> row;
    for (int j = 0; j < 9; j++) {
      if (boardToPrint[i][j][0] == '-') {
        row.push_back('.');
      } else if (boardToPrint[i][j][0] - '0' >= 1 && boardToPrint[i][j][0] - '0' <= 9) {
        row.push_back(boardToPrint[i][j][0]);
      } else if (boardToPrint[i][j][0] == '\0') {
        row.push_back('.');
      } else {
        correctSudoku = false;
        break;
      }
    }
    boardToSolve.push_back(row);
  }
}

void SudokuSolver::sudokuAbleToSolve(std::vector<std::vector<char>> &correctBoard, bool &ableToSolve) {
  std::unordered_set<int> rows[9];
  std::unordered_set<int> columns[9];
  std::unordered_set<int> boxes[9];

  for (int r = 0; r < 9; r++) {
      for (int c = 0; c < 9; c++) {
          if (correctBoard[r][c] == '.') continue;

          char value = correctBoard[r][c];
          int boxIndex = (r / 3) * 3 + c / 3;

          if (rows[r].count(value) || columns[c].count(value) || boxes[boxIndex].count(value)) {
            ableToSolve = false;
            return;
          }
          rows[r].insert(value);
          columns[c].insert(value);
          boxes[boxIndex].insert(value);
      }
  }
}

void SudokuSolver::loadSudoku(char (&board)[9][9][2]) {
  std::ifstream inputFile;

  const char RANDOMSUDOKUNUMBER = int(1. * rand() / RAND_MAX * 9) + 1 + '0';
  std::string fileName = "sudokusToLoadData/";
  fileName += RANDOMSUDOKUNUMBER;
  fileName += ".txt";

  inputFile.open(fileName);

  std::vector<std::vector<char>> sudoku;

  if (!inputFile.is_open()) {
    
  } else {
    std::string line;
    int r = 0;
    while (getline(inputFile, line)) {
      for (int i = 0; i < 9; i++) {
        board[r][i][0] = line[i];
      }
      r++;
    }
    inputFile.close();
  }
}
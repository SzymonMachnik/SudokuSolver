// sudoku.h

#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>
#include <iostream>

class SudokuSolver {
  private:
    bool isValid(int r, int c, char value, std::vector<std::vector<char>>& board);
    void backTrack(std::vector<std::vector<char>>& boardOriginal, int r, int c, bool& solved);

  public:
    SudokuSolver();
    // void initializeBoard();
    void solveSudoku(std::vector<std::vector<char>>& board);
    // void renderBoard(char board[9][9][2]);  // Przekazanie planszy do renderowania
};

#endif
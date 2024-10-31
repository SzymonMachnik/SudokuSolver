// sudoku.h

#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_set>

class SudokuSolver {
  private:
    bool isValid(int r, int c, char value, std::vector<std::vector<char>>& board);
    void backTrack(std::vector<std::vector<char>>& boardOriginal, int r, int c, bool& solved);

  public:
    SudokuSolver();
    void solveSudoku(std::vector<std::vector<char>>& board);

    void InitializeBoard(char (&board)[9][9][2]);
    void resetBoard(char (&board)[9][9][2]);
    void translateSolvedBoardIntoBoardToPrint(char (&boardToPrint)[9][9][2], std::vector<std::vector<char>> &solvedBoard);
    void translateBoardToPrintIntoBoardToSolve(char (&boardToPrint)[9][9][2], std::vector<std::vector<char>> &boardToSolve, bool &correctSudoku);
    void sudokuAbleToSolve(std::vector<std::vector<char>> &correctBoard, bool &ableToSolve);

    void loadSudoku(char (&board)[9][9][2]);
};

#endif
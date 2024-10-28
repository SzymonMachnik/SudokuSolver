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

// void SudokuSolver::renderBoard(char board[9][9][2]) {
//     // Tutaj umieść kod renderujący planszę, jeśli to potrzebne
// }
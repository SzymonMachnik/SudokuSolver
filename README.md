# Sudoku Solver
## 📃 Brief description
I have created this project beacuse I have been strongly interested in mathematical side of Sudoku. It has motivated me to try my best and design an algorithm basing on back tracking method which is able to solve this japanese game in no time.
## ✨ Features
- **Algotihm:** I have designed high-performance alogrithm using back tracking and unordered set to save memory. I put the pseudocode below.
- **User abilities:** User is able to enter sudoku by his own but also he can use the built in "load" function which fills board by random sudoku.
## ⚙ How algorithm works
```
Function isValid(r, c, value, &board):
  For i from 0 to 8:
    If board[i][c] == value or board[r][i] == value or current 3x3 block containing value:
      Return false
  Return true

Function backTrack(&board, r, c, &solved):
  If sudoku is solved (solved == true), end the function

  If the position (r, c) is empty:
    For each digit i from 1 to 9:
      If isValid(r, c, i as a character, board) == true:  // Check if we can put i (does not exist in the same row, column, or 3x3 block)
        Set board[r][c] to the i
        Call backTrack with the next position (r + 1, c)
        If solved == true, end the function
        Undo the change to board[r][c] by setting it back to '.'
  Else, call backTrack with the next position (r + 1, c)  // If the cell board[r][c] is filled by default, move to the next cell

Function solveSudoku(&board):
  Set solved to false
  Call backTrack(board, 0, 0, solved)
```
## 📜 Credits
Dear ImGui for graphical user interface:
- Github: https://github.com/ocornut/imgui
- Website: https://github.com/ocornut/imgui

Roboto font for letters style:
- Website: https://fonts.google.com/specimen/Roboto

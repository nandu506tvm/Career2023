/*
Given a partially filled Sudoku matrix of 9x9
Write a function to solve this sudoku board.
*/

#include <iostream>

using namespace std;

vector<vector<int>> board = {{5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0}, {0, 9, 8, 0, 0, 0, 0, 6, 0},
                             {8, 0, 0, 0, 6, 0, 0, 0, 3}, {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 2, 0, 0, 0, 6},
                             {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5}, {0, 0, 0, 0, 8, 0, 0, 7, 9}};

void printBoard() {
    for (auto element : board) {
        for (auto ele : element) {
            cout << ele << "\t";
        }
        cout << endl;
    }
}

bool isPlacementValid(int row, int col, int choice) {
    // check if placement breaks the row/column
    for (int i = 0; i < board.size(); i++) {
        if ((board[row][i] == choice) or (board[i][col] == choice)) {
            return false;
        }
    }
    // check if placement breaks sub-grid
    // To get the 3x3 subgrid:,
    // divide the row/col by 3 and then multiply result by 3
    int sub_grid_row_start = (row / 3) * 3;
    int sub_grid_col_start = (col / 3) * 3;
    for (int i = sub_grid_row_start; i < sub_grid_row_start + 3; i++) {
        for (int j = sub_grid_col_start; j < sub_grid_col_start + 3; j++) {
            if (board[i][j] == choice) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int curr_row, int curr_col) {
    // GOAL - All rows are filled
    if (curr_row >= board.size()) {
        return true;
    }
    // column exhausted, move to next row
    if (curr_col >= board.size()) {
        return solveSudoku(curr_row + 1, 0);
    }
    // check if the current cell is pre-filled
    if (board[curr_row][curr_col] != 0) {
        return solveSudoku(curr_row, curr_col + 1);
    }
    // try to fill the present cell
    for (int choice = 1; choice <= 9; choice++) {
        if (isPlacementValid(curr_row, curr_col, choice)) {
            board[curr_row][curr_col] = choice;
            // Assume recursion will solve all other cells
            bool other_cells_solved = solveSudoku(curr_row, curr_col + 1);
            // Our choice is correct
            if (other_cells_solved) {
                return true;
                // Our choice is wrong, revert our choice
            } else {
                board[curr_row][curr_col] = 0;
            }
        }
    }
    // we didn't return from above loop
    // Hence no solutions found
    return false;
}

int main(int argc, char const *argv[]) {
    bool result = solveSudoku(0, 0);
    if (result) {
        printBoard();
    }
    return 0;
}

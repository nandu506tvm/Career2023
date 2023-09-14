/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or
vertically neighboring. The same letter cell may not be used more than once.


Sample Input:
    board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
    word = "ABCCED"
*/

#include <iostream>

using namespace std;

// Use this to check for other characters in the grid
bool findWord(int row, int column, vector<vector<char>> &board, string word, int curr_idx) {
    // Base condition - word found
    if (word.length() == curr_idx) {
        return true;
    }

    // Board boundary checks
    if (row >= board.size() || column >= board[0].size() || row < 0 || column < 0) {
        return false;
    }

    // current character not equal to word character
    if (board[row][column] != word[curr_idx]) {
        return false;
    }

    // Mark the cell as visited using '#'.
    char temp = board[row][column];
    board[row][column] = '#';

    // move right,left,down,up
    bool right_result = findWord(row, column + 1, board, word, curr_idx + 1);
    bool left_result = findWord(row, column - 1, board, word, curr_idx + 1);
    bool up_result = findWord(row + 1, column, board, word, curr_idx + 1);
    bool down_result = findWord(row - 1, column, board, word, curr_idx + 1);

    // Backtrack step
    board[row][column] = temp;

    return right_result || left_result || up_result || down_result;
}

bool wordSearch(vector<vector<char>> &board, string word) {
    int row = board.size();
    int column = board[0].size();

    // Iterate through the grid.
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            // First character is matching, search for rest
            if (word[0] == board[i][j]) {
                // Entire word found
                if (findWord(i, j, board, word, 0)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main(int argc, char const *argv[]) {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << wordSearch(board, word) << endl;
    return 0;
}

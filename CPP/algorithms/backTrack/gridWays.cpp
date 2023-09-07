/*
Given a MxN grid, find the number of ways to reach the bottom right corner
starting from top left corner. At each cell, we can move right or down
*/

#include <iostream>

using namespace std;

void findGridWays(int current_row, int current_col, int row, int column, int &ways) {
    // Reached finishing point, increment 'ways'
    if (current_row == row and current_col == column) {
        ways += 1;
        return;
    }
    // We went out of bound, in that case return
    if (current_row > row or current_col > column) return;

    // Move down first
    findGridWays(current_row + 1, current_col, row, column, ways);

    // Then explore the right path
    findGridWays(current_row, current_col + 1, row, column, ways);
}

int main(int argc, char const *argv[]) {
    int row, column, ways = 0;
    cout << "Enter Row size: ";
    cin >> row;
    cout << "Enter Column size: ";
    cin >> column;

    findGridWays(0, 0, row - 1, column - 1, ways);
    cout << "Number of Paths: " << ways << endl;

    return 0;
}

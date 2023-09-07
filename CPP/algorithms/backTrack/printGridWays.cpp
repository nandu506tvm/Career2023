/*
Given a MxN grid, find all the ways to reach the bottom right corner
starting from top left corner. At each cell, we can move right or down
*/

#include <iostream>

using namespace std;

vector<vector<string>> result;

void findGridWays(int current_row, int current_col, int row, int column, vector<string> &ways) {
    // Reached finishing point, increment 'ways'
    if (current_row == row and current_col == column) {
        result.push_back(ways);
        return;
    }
    // We went out of bound, in that case return
    if (current_row > row or current_col > column) return;

    // Move down first
    ways.push_back("Down");
    findGridWays(current_row + 1, current_col, row, column, ways);
    ways.pop_back();

    // Then explore the right path
    ways.push_back("Right");
    findGridWays(current_row, current_col + 1, row, column, ways);
    ways.pop_back();
}

int main(int argc, char const *argv[]) {
    int row, column = 0;
    cout << "Enter Row size: ";
    cin >> row;
    cout << "Enter Column size: ";
    cin >> column;

    vector<string> ways;
    findGridWays(0, 0, row - 1, column - 1, ways);

    // Print the valid paths
    for (auto element : result) {
        for (auto ele : element) {
            cout << ele << "\t";
        }
        cout << endl;
    }

    return 0;
}

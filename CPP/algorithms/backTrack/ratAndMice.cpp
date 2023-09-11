/*
You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty.
The rat can move from a position towards left, right, up or down on the grid.
Initially rat is on the position (1,1). It wants to reach position (N,M) where its mice is waiting for.
There exits a unique path in the grid . Find that path and help the rat reach its mice.

Input Format:
            Given vector of strings representing a grid with N rows and M columns.
            'X' in position (i,j) denotes that the cell is blocked and 'O' denotes that the cell is empty.

Output Format:
            Print N lines, containing M integers each.
            A 1 at a position (i,j) denotes that the (i,j)th cell is covered in the path.
            A 1 at a position (i,j) denotes that the (i,j)th cell is not covered.
*/

#include <iostream>

using namespace std;

vector<vector<int>> PATH;

bool isSafe(int row, int col, vector<vector<int>> &visited) {
    // Out of bound check
    if ((row >= PATH.size()) or (col >= PATH[0].size())) {
        return false;
    }
    // check if path is already visited
    if (visited[row][col] == 1) {
        return false;
    }
    // check if path is blocked
    if (PATH[row][col] == -1) {
        return false;
    }
    return true;
}

// TODO - convert the multiple 'if' statements into a single for loop
bool findPath(int curr_row, int curr_col, vector<vector<int>> &grid, vector<vector<int>> &visited, bool &sol_found) {
    // We reached the final point
    if ((curr_row == grid.size() - 1) and (curr_col == grid[0].size() - 1)) {
        sol_found = true;
        return true;
    }
    // Make choices - right, left, top, down
    // Move right
    if (isSafe(curr_row, curr_col + 1, visited)) {
        if (sol_found) {
            return true;
        }
        grid[curr_row][curr_col + 1] = 1;
        visited[curr_row][curr_col + 1] = 1;
        bool result = findPath(curr_row, curr_col + 1, grid, visited, sol_found);
        if (result) {
            return true;
        }
        grid[curr_row][curr_col + 1] = 0;
    }

    // Move left
    if (isSafe(curr_row, curr_col - 1, visited)) {
        if (sol_found) {
            return true;
        }
        grid[curr_row][curr_col - 1] = 1;
        visited[curr_row][curr_col - 1] = 1;
        bool result = findPath(curr_row, curr_col - 1, grid, visited, sol_found);
        if (result) {
            return true;
        }
        grid[curr_row][curr_col - 1] = 0;
    }

    // move down
    if (isSafe(curr_row + 1, curr_col, visited)) {
        if (sol_found) {
            return true;
        }
        grid[curr_row + 1][curr_col] = 1;
        visited[curr_row + 1][curr_col] = 1;
        bool result = findPath(curr_row + 1, curr_col, grid, visited, sol_found);
        if (result) {
            return true;
        }
        grid[curr_row + 1][curr_col] = 0;
    }

    // move up
    if (isSafe(curr_row - 1, curr_col, visited)) {
        if (sol_found) {
            return true;
        }
        grid[curr_row - 1][curr_col] = 1;
        visited[curr_row - 1][curr_col] = 1;
        bool result = findPath(curr_row - 1, curr_col, grid, visited, sol_found);
        if (result) {
            return true;
        }
        grid[curr_row - 1][curr_col] = 0;
    }
    return false;
}

int main(int argc, char const *argv[]) {
    vector<string> arr = {"OXOOOOX", "OXOXOXX", "OXOXOOX", "OOOXOXX", "XXOXOOO"};
    int row = arr.size();
    int col = arr[0].length();

    // convert the input to 2d matrix (PATH)
    for (string element : arr) {
        vector<int> temp;
        for (auto ch : element) {
            if (ch == 'X') {
                temp.push_back(-1);
            } else {
                temp.push_back(0);
            }
        }
        PATH.push_back(temp);
    }

    bool sol_found = false;
    vector<vector<int>> grid(row, vector<int>(col, 0));
    vector<vector<int>> visited(row, vector<int>(col, 0));
    grid[0][0] = 1;
    visited[0][0] = 1;
    cout << findPath(0, 0, grid, visited, sol_found) << endl;

    return 0;
}

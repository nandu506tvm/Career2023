/* Place N queens on a NxN chess board
   No two queens should be in non-attacking solution
*/
#include <iostream>

using namespace std;

vector<vector<int>> result;

// Check if present board placements are valid
bool validPlacement(int N, vector<int> &col_placements) {
    int row_id = col_placements.size() - 1;
    for (int i = 0; i < row_id; ++i) {
        int diff = abs(col_placements[i] - col_placements[row_id]);
        if (diff == 0 || diff == row_id - i) {
            return false;
        }
    }
    return true;
}

void placeNQueens(int row, int N, vector<int> &col_placements, bool &found) {
    if (row == N) {
        result.push_back(col_placements);
        found = true;
        return;
    }

    for (int i = 0; i < N; ++i) {
        col_placements.push_back(i);
        if (validPlacement(N, col_placements)) {
            placeNQueens(row + 1, N, col_placements, found);
        }
        if (found) return;
        col_placements.pop_back();
    }
}

int main(int argc, char const *argv[]) {
    int N = 2;
    cout << "Enter chess board size: ";
    cin >> N;
    vector<int> col_placements;
    bool found = false;
    placeNQueens(0, N, col_placements, found);

    // print the possible combinations
    int count = 0;
    for (auto element : result) {
        count++;
        for (auto ele : element) {
            cout << ele << "\t";
        }
        cout << endl;
    }
    cout << count << endl;
    return 0;
}

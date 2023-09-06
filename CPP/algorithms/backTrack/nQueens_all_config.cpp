/* Place N queens on a NxN chess board
   No two queens should be in non-attacking solution
*/
#include <iostream>

using namespace std;

vector<vector<int>> result;

// Check if present board placements are valid
bool validPlacement(int N, vector<int> &col_placements) {
    // The last element in the vector will be the newly added queen.
    // We need to check if this new placement is breaking the rows above it.
    int row_id = col_placements.size() - 1;
    for (int i = 0; i < row_id; ++i) {
        int diff = abs(col_placements[i] - col_placements[row_id]);

        // diff = 0 indicates there is a queen in same column in the rows above.
        // Second check is for diagonal threat detection.
        if (diff == 0 || diff == row_id - i) {
            return false;
        }
    }
    return true;
}

void placeNQueens(int row, int N, vector<int> &col_placements) {
    // After all rows are filled, add the col_placements to result
    if (row == N) {
        result.push_back(col_placements);
        return;
    }

    // we can try placing the queen in each column
    for (int i = 0; i < N; ++i) {
        col_placements.push_back(i);
        // If the above placement is valid, recurse down that path for filling next row
        if (validPlacement(N, col_placements)) {
            placeNQueens(row + 1, N, col_placements);
        }

        // If there is no valid placement for present row -> Backtrack
        // Or we have found one solution and has to check for other soln - Backtrack
        col_placements.pop_back();
    }
}

int main(int argc, char const *argv[]) {
    int N = 2;
    cout << "Enter chess board size: ";
    cin >> N;
    vector<int> col_placements;
    placeNQueens(0, N, col_placements);

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

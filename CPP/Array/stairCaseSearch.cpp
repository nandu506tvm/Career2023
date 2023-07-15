#include <iostream>
#include <vector>

using namespace std;

bool stairCaseSearch(vector<vector<int>> arr, int row, int column, int key) {
    int row_id = 0;
    int column_id = column - 1;

    // When we go out of bound, element is not found
    while (row_id < row && column_id >= 0) {
        // Element found
        if (arr[row_id][column_id] == key) return true;

        // ignore searching on current column
        if (arr[row_id][column_id] > key) {
            column_id--;
        }

        // igore searching on current row
        else {
            row_id++;
        }
    }
    return false;
}

int main() {
    // Row wise, column wise sorted array
    vector<vector<int>> arr{{1, 2, 3, 4, 19},
                            {5, 6, 7, 8, 20},
                            {9, 10, 11, 12, 21},
                            {13, 14, 15, 16, 22}};

    cout << stairCaseSearch(arr, 4, 5, 30) << endl;

    return 0;
}

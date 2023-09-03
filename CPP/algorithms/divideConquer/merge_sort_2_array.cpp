#include <iostream>

using namespace std;

/*
To merge sort a 2D array row-wise and column-wise in C++, you can use a combination of merge sort algorithms for both
rows and columns. Here's how you can do it:

Merge Sort Rows:

For each row in the 2D array, apply the merge sort algorithm to sort the elements within that row.
Merge Sort Columns:

To sort columns, you will need to transpose the 2D array (swap rows and columns).
Apply the merge sort algorithm on the transposed array to sort the new rows.
Transpose the sorted transposed array back to its original form to get the sorted columns.
*/

vector<vector<int>> merge_sort_2d_array(int row, int column, vector<vector<int>> arr) {
    // Base condition
    // sort the row
    // sort the column
    // Merge the final output
}

int main(int argc, char const *argv[]) {
    vector<vector<int>> arr = {{18, 4, 16, 8}, {23, 13, 20, 11}, {28, 24, 26, 25}, {1, 30, 15, 19}};

    return 0;
}

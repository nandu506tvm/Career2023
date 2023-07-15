/*
 * Given 2d array of N*N integers and given Q queries
 * In each query given four points - a,b,c,d
 * Print sum of square represented by (a,b) as top left point,
 * (c,d) as bottom right point.
 *
 * This above can be accomplished using prefix sum of 2D array
 * */

#include <iostream>
#include <vector>

using namespace std;

// To calculate the prefix sum for a coordinate (1,1) do the following
// Add the element to the immediate top of (1,1) and to the immedidate left of
// (1,1) Subtract the element at immediate top diagonal position of (1,1)
// Subtraction is required to avoid repetition of that diagonal element in
// further calcuations.
void prefixSumCalculate(vector<vector<int>> arr,
                        vector<vector<int>> &prefix_sum, unsigned int row_size,
                        unsigned int column_size) {
    for (unsigned int row = 1; row <= row_size; row++) {
        for (unsigned int column = 1; column <= column_size; column++) {
            // Get the element from the original array
            int arr_element = arr[row - 1][column - 1];

            // Logic to calculate prefix sum
            prefix_sum[row][column] =
                (arr_element + prefix_sum[row - 1][column] +
                 prefix_sum[row][column - 1]) -
                prefix_sum[row - 1][column - 1];
        }
    }
}

int main() {
    vector<vector<int>> arr{
        {1, 2, 0, 4}, {3, 4, 2, 2}, {3, 0, 1, 4}, {0, 2, 1, 3}};

    unsigned int row_size = arr.size();
    unsigned int column_size = arr[0].size();

    // We create a 2D vector containing "row_size"
    // elements each having the value "vector<int> (column_size, 0)".
    // "vector<int> (column_size, 0)" means a vector having "column_size"
    // elements each of value "0".
    // Here these elements are vectors.
    // we are creating one additional row/column for prefix sum matrix
    vector<vector<int>> prefix_sum(row_size + 1,
                                   vector<int>(column_size + 1, 0));

    // The prefix_sum[i][j] represents sum of all elements from (0,0) to (i,j)
    prefixSumCalculate(arr, prefix_sum, row_size, column_size);

    // print the prefix sum matrix
    for (unsigned int row = 0; row <= row_size; row++) {
        for (unsigned int column = 0; column <= column_size; column++) {
            cout << prefix_sum[row][column] << "\t";
        }
        cout << endl;
    }

    return 0;
}

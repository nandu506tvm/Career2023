#include <iostream>

/*
 * You are given an n x n 2D matrix representing an image.
 * rotate the image by 90 degrees (clockwise).
 * DO NOT allocate another 2D matrix and do the rotation.
 *
 * */

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int row_length = matrix.size();
    int column_length = matrix[0].size();

    // Get the tranpose of the matrix i.e interchange row-column
    for (int row = 0; row < row_length; row++) {
        for (int column = 0; column < row; column++) {
            swap(matrix[row][column], matrix[column][row]);
        }
    }

    // Now reverse each column to get the 90 degree rotation of array
    for (int row = 0; row < row_length; row++) {
        int start = 0;
        int end = column_length - 1;

        while (start < end) {
            swap(matrix[row][start], matrix[row][end]);
            start++;
            end--;
        }
    }
}

int main() {
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    rotate(arr);

    // Print the final array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

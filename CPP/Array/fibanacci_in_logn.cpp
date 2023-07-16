#include <iostream>
#include <vector>

using namespace std;

/* Multiply the two matrix, innermost loop does the multiplication
 * Inside Innermost loop: For multiplicant matrix a, row is constant
 * For mulitplier matrix b, column is constant.
 */
vector<vector<int>> multiply_matrix(vector<vector<int>> a, vector<vector<int>> b, int matrix_size) {
    vector<vector<int>> mul_result(matrix_size, vector<int>(matrix_size, 0));
    for (int row = 0; row < matrix_size; ++row) {
        for (int column = 0; column < matrix_size; ++column) {
            for (int k = 0; k < matrix_size; ++k) {
                mul_result[row][column] += a[row][k] * b[k][column];
            }
        }
    }
    return mul_result;
}

/* Calculate (base_matrix^n) using binary exponentiation method
 * Element at position [0][1] of the resultant matrix will have the result */
int find_fibanacci(int num) {
    int matrix_size = 2;
    vector<vector<int>> base_matrix = {{1, 1}, {1, 0}};
    vector<vector<int>> result(matrix_size, vector<int>(matrix_size, 1));
    while (num > 0) {
        if (num & 1) {
            result = multiply_matrix(result, base_matrix, matrix_size);
        }
        num = num >> 1;
        base_matrix = multiply_matrix(base_matrix, base_matrix, matrix_size);
    }
    return result[0][1];
}

int main(int argc, char const *argv[]) {
    int number = 1;
    cout << "Enter a number: ";
    cin >> number;
    cout << find_fibanacci(number) << endl;
    return 0;
}

#include <iostream>

using namespace std;


int main() 
{
    vector<vector<int>> arr = {
                        {1,2,3},
                        {4,5,6},
                        {7,8,9},
    };

    // inter change the rows and columns to get the tranponse of the above matrix
    int row_size = arr.size();
    int column_size = arr[0].size();

    for (int row=0; row< row_size; row++)
    {
        for (int column=0; column < row; column++)
        {
            swap(arr[row][column], arr[column][row]);
        }
    }

    // Print the transpose
    for (int i=0; i<row_size; i++)
    {
        for (int j=0; j < column_size; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}


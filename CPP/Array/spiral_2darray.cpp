#include <iostream>
#include <vector>

using namespace std;

void spiralPrint (vector<vector<int>> arr)
{
    int direction=0;

    // Declare row level pointer
    int first_row = 0;
    int last_row = arr.size()-1;

    // Declare column level pointer;
    int first_column = 0;
    int last_column = arr[0].size()-1;

    while(first_row <= last_row && first_column <= last_column)
    {
        // Move from left to right
        if (direction == 0)
        {
            for (int column_num=first_column; column_num <= last_column; column_num++)
            {
                cout << arr[first_row][column_num] << "\t";
            }
            cout << endl;
            first_row++;

        }
        // Move from top to bottom
        else if (direction == 1)
        {
            for (int row_num=first_row; row_num <= last_row; row_num++)
            {
                cout << arr[row_num][last_column] << "\t"; 
            }
            cout << endl;
            last_column--;
        }
        // Move for right to left
        else if (direction == 2)
        {
            for (int column=last_column; column >= first_column; column--)
            {
                cout << arr[last_row][column] << "\t";
            }
            cout << endl;
            last_row--;
        }
        // Move for bottom to top
        else if (direction == 3)
        {
            for (int row=last_row; row >= first_row; row--)
            {
                cout << arr[row][first_column] << "\t";
            }
            cout << endl;
            first_column++;
        }

        // Update the direction to move in next direction
        direction = (direction+1)%4;
    }
}

int main() 
{
    vector <vector<int> > arr
    {
        {1,2,3,4,19},
        {5,6,7,8,20},
        {9,10,11,12,21},
        {13,14,15,16,22}
    };
        

    // Print the 2d array in spiral
    spiralPrint(arr);

    return 0;

}


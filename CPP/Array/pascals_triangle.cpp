#include <iostream>

using namespace std;

vector<vector<int>> printPascal(int num)
{
    vector<vector<int>> result;

    // row iteration
    for (int row=0; row<num; row++)
    {
        // Inner vector should be one greater than present row in pascals triangle
        vector<int> inner_vector(row+1,1);

        for (int index=1; index<row; index++)
        {
            inner_vector[index] = result[row-1][index-1] + result[row-1][index];
        }

        // see here we are pushing back a vector
        result.push_back(inner_vector);

    }

    return result;
}


int main() 
{
    int num;

    cout << "Enter a positive integer: ";
    cin >> num;
    vector<vector<int>> result = printPascal(num);

    for (int row=0; row<num; row++)
    {
        for (int column=0; column<=row; column++)
        {
            cout << result[row][column] << "\t";
        }
        cout << endl;
    }

    
    return 0;
}


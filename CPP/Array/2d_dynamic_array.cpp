#include <iostream>

using namespace std;

/* we have to do dynamic memory allocation for each row of 2d array.
 * Then store each of those addresses in a array of pointers.
 * we will also store the address pointing to array of pointers using double pointer variable.
 * */
int ** create_2d_array(unsigned int row, unsigned int column)
{
    // array of pointers to store the starting address of rows
    int **arr_of_pointers = new int* [row];

    for (int i=0; i<row; i++)
    {
        // create each row and store it in array of pointers
        arr_of_pointers[i] = new int[column];
    }

    // Deallocation
    for (int i=0; i<row; i++)
    {
        delete [] arr_of_pointers[i]
    }

    delete [] arr_of_pointers;

    arr_of_pointers = NULL;

    return arr_of_pointers;

}

int main() 
{
    int **arr = create_2d_array(5,4);

    return 0;
}


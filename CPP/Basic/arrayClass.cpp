#include <iostream>
#include <array>

using namespace std;

void printArray (const array<char,5> &arr) {
    for (char element: arr) {
        cout << element << "\t";
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {

    // Declare an array object
    array<char,5> arr = {'a','b','c','d','e'};
    array<char,5> arr2;

    // Print array element at index 1
    cout << arr.at(1) << endl;

    // Print first element in array
    cout << arr.front() << endl;

    // Print last element in array
    cout << arr.back() << endl;

    // Print array size
    cout << arr.size() << endl;

    // Initialize all arr2 elements with 'a'
    arr2.fill('f');

    // swap arr, arr2 elements
    arr.swap(arr2);

    // Print the arrays
    printArray(arr);
    printArray(arr2);

    // Check if array is empty
    if (!arr.empty()) {
        cout << "Array is not empty" << endl;
    }

    // Get the array starting pointer
    char *p = arr2.data();
    cout << "Element at address " << p << " is: " << *p <<endl;


    return 0;
}


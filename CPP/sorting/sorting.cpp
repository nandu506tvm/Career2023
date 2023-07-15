#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    vector<int> arr = {10, 9, 5, 8, 3, 2, 11, 101, 1};

    // Inbuilt sorting algorithm uses 'introsort'
    // argument 1 -> pointer from where sorting should start in array.
    // argument 2 -> pointer to one next of last element in array
    sort(arr.begin(), arr.end());

    // Print the array
    for (int element : arr) {
        cout << element << "\t";
    }
    cout << endl;

    return 0;
}

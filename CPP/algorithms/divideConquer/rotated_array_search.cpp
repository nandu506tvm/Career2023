/*
 * Write a function that takes input an sorted array of distinct integers.
 * The array is rotated about a pivot point.
 * Search for an element in that array and return its index.
 * If element is not found, return -1
 */

#include <iostream>

using namespace std;

int modified_binary_search(const vector<int> arr, int key) {
    int start_index = 0;
    int end_index = arr.size() - 1;
    int mid = 0;

    while (start_index <= end_index) {
        mid = (start_index + end_index) / 2;

        // Check if element is present at mid
        if (arr[mid] == key) return mid;

        // check if left array is sorted
        if (arr[start_index] <= arr[mid]) {
            // check if key falls within this sorted part
            if (key >= arr[start_index] and key <= arr[mid]) {
                end_index = mid;
            } else {
                start_index = mid + 1;
            }
        }
        // check if right array is sorted
        else if (arr[mid + 1] <= arr[end_index]) {
            // check if key falls within this sorted part
            if (key >= arr[mid + 1] and key <= arr[end_index]) {
                start_index = mid + 1;
            } else {
                end_index = mid + 1;
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    int num;
    vector<int> arr = {7, 9, 10, 1, 2, 3, 4, 5, 6};

    cout << "Enter element to be searched: ";
    cin >> num;

    cout << modified_binary_search(arr, num) << endl;

    return 0;
}

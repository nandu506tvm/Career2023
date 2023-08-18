#include <iostream>

using namespace std;

/* Function to partition the array in O(1) space complexity.
 * Select a pivot and rearrange elements.
 * Elements left of pivot is smaller.
 * Elements right of pivot is greater.
 * Return the index of the pivot element.
 */
int partition(vector<int> &arr, int start_index, int end_index) {
    int pivot = arr[end_index];
    int pivot_index = start_index;

    // walk through the array and swap if element is lesser than pivot and then increment pivot_index
    for (int i = start_index; i < end_index; ++i) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[pivot_index]);
            pivot_index++;
        }
    }

    // Now we have to move the pivot element to the correct position
    swap(arr[end_index], arr[pivot_index]);

    return pivot_index;
}

/* Unlike merge sort, quick sort  does everything 'in place' */
void quick_sort(vector<int> &arr, int start_index, int end_index) {
    // Base case
    if (start_index >= end_index) return;

    // Partition the array and return the index of pivot after re-arrangement
    int pivot_index = partition(arr, start_index, end_index);

    // Recursively sort elements at left and right of pivot
    // This can be a bottleneck, if the two paritions are not equally split.
    // Such a case will have a worst case time complexity of O(n^2).
    // To avoid this, select pivot randomly in partition function.
    quick_sort(arr, start_index, pivot_index - 1);
    quick_sort(arr, pivot_index + 1, end_index);
}

int main(int argc, char const *argv[]) {
    vector<int> arr = {-100, -10, 100, 0, -1, 13, 5, 100, 35, 70};

    // Sort the array
    quick_sort(arr, 0, arr.size() - 1);

    // Print the sorted array
    for (auto element : arr) {
        cout << element << "\t";
    }
    cout << endl;

    return 0;
}

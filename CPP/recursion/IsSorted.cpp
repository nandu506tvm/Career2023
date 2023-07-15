#include <iostream>

using namespace std;

bool IsSorted(vector<int> arr, int start_index, int end_index) {
    // Base condition
    if (start_index == end_index) {
        return true;
    }
    // Assume recursion will solve this
    bool is_remaining_elem_sorted = IsSorted(arr, start_index + 1, end_index);

    // Final calculation
    if (arr[start_index] < arr[start_index + 1] and is_remaining_elem_sorted) {
        return true;
    }

    // Above check failed
    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    cout << IsSorted(arr, 0, arr.size() - 1) << endl;
    return 0;
}

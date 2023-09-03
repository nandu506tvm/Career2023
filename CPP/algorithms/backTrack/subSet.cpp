#include <iostream>

using namespace std;

// Global array to store the result
vector<vector<char>> result;

void generateSubSet(const vector<char> &arr, vector<char> &subset, int idx) {
    // When should i stop and add the result to subset
    if (idx == arr.size()) {
        result.push_back(subset);
        return;
    }

    // At each level we have two options, either to add the element or not
    // We are adding the element at index 'idx' to subset and generate all other subsets
    subset.push_back(arr[idx]);
    generateSubSet(arr, subset, idx + 1);

    // Add the backtrack step here since 'subset' is passed by reference
    // By removing the last element added,  we effectively "undo" the inclusion of that element in the current subset,
    // so that we can proceed to explore other possibilities
    subset.pop_back();

    // Now generate subset without adding the element at index 'idx'
    generateSubSet(arr, subset, idx + 1);
}

int main(int argc, char const *argv[]) {
    vector<char> arr = {'a', 'b', 'c'};
    vector<char> subset = {};
    generateSubSet(arr, subset, 0);

    // Print the output
    for (auto element : result) {
        for (auto ele : element) {
            cout << ele << "\t";
        }
        cout << endl;
    }
    return 0;
}

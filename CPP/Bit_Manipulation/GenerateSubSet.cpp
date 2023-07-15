#include <iostream>
#include <vector>

using namespace std;

// Total number of subsets for an array of size N is (2^N) including empty set
// This bit manipulation alg runs in (N*O(N))
void GenerateSubSet(vector<int> vect, vector<vector<int>> &result) {
    int arr_size = vect.size();

    // This is equivalent to doing (2^n)
    // This will give us the total number of subsets
    int subset_count = 1 << arr_size;

    // Outer loop for 2^N subset generation
    for (int mask = 0; mask < subset_count; mask++) {
        vector<int> subset;

        // walk bit by bit through the 'mask' and see what all bits are set
        for (int array_index = 0; array_index < arr_size; array_index++) {
            // If the bit is set, then push the element at that particular index
            // to subset.
            if (mask & (1 << array_index)) {
                subset.push_back(vect[array_index]);
            }
        }
        result.push_back(subset);
    }
}

int main() {
    vector<int> vect = {1, 2, 3, 4, 5};
    vector<vector<int>> result;
    GenerateSubSet(vect, result);

    // Print the result
    for (auto element : result) {
        for (auto ele : element) {
            cout << ele << "\t";
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// Find the closest pair that has sum nearest to X.
// Time complexity -> O(nlogn)
pair<int, int> closestSum(vector<int> arr, int x) {
    // Pair STL data structure to hold the resultant pair
    pair<int, int> closest_sum_pair;

    // Get Array length
    int arr_length = arr.size() - 1;

    // Variable to hold the mindiff that we found so far
    int min_diff = INT_MAX;

    // Walk through the list
    for (int index = 0; index < arr_length; index++) {
        int first_element = arr[index];

        int left_index = index + 1, right_index = arr_length;

        // Do a binary search to find the 'elem' in the array
        // such that 'first_element' + 'elem' is closest to 'x'
        while (left_index <= right_index) {
            int mid = (left_index + right_index) / 2;

            // we found a pair whose sum is equal to 'x'
            if (first_element + arr[mid] == x) {
                closest_sum_pair.first = first_element;
                closest_sum_pair.second = arr[mid];
                min_diff = 0;
                break;
            }
            // Find the present pair sum difference with 'x'
            // Compare the value with min_diff variable
            if ((first_element + arr[mid]) - x < min_diff) {
                closest_sum_pair.first = first_element;
                closest_sum_pair.second = arr[mid];
                min_diff = abs((first_element + arr[mid]) - x);
            }

            // Need to search only left of mid
            if (first_element + arr[mid] > x) {
                right_index = right_index - 1;
            }
            // Need to search only right of mid
            else {
                left_index = left_index + 1;
            }
        }
    }

    return closest_sum_pair;
}

int main(int argc, char const *argv[]) {
    vector<int> arr = {10, 22, 28, 29, 30, 40};
    pair<int, int> closest_sum_pair = closestSum(arr, 54);

    cout << closest_sum_pair.first << "," << closest_sum_pair.second << endl;

    return 0;
}

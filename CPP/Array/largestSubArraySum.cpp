// Find the largest subarray sum and return it

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> findprefixSumList(vector<int> list, int length) {
    vector<int> result(length, 0);
    result[0] = list[0];

    for (int index = 1; index < length; index++) {
        result[index] = result[index - 1] + list[index];
    }
    return result;
}

// Optimized Using prefix Sum
// Sum of subarray[i,j] =
int largestSubArraySum2(vector<int> list) {
    int result = 0;
    int subarray_sum = 0;
    int length = list.size();

    // Find the prefix sum of given list
    vector<int> prefix_sum_list = findprefixSumList(list, length);

    // Find max from prefix_sum_list
    result = *max_element(prefix_sum_list.begin(), prefix_sum_list.end());

    for (int i = 1; i < length; i++) {
        for (int j = i; j < length; j++) {
            // subarray sum [i,j] = prefix_sum[j] - prefix_sum[i-1]
            subarray_sum = prefix_sum_list[j] - prefix_sum_list[i - 1];
        }
        result = max(subarray_sum, result);
    }

    return result;
}

// Brute force approach - O(n^3)
int largestSubArraySum(vector<int> list) {
    int result = 0;
    int subarray_sum = 0;
    int length = list.size();

    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            subarray_sum = 0;
            for (int k = i; k <= j; k++) {
                subarray_sum += list[k];
            }
            result = max(subarray_sum, result);
        }
    }

    return result;
}

int main(int argc, char const *argv[]) {
    vector<int> list = {1, 2, 3, -4, 5};
    cout << largestSubArraySum(list) << endl;
    cout << largestSubArraySum2(list) << endl;

    return 0;
}

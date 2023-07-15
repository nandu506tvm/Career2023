// Find the largest subarray sum and return it

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// Using kadane's algoritm
int largestSubArraySum(vector<int> list) {
    int current_sum = 0;
    int max_sum = INT_MIN;

    for (int element : list) {
        // Add the element to sum
        current_sum += element;

        // compare the sum with max_sum
        max_sum = max(current_sum, max_sum);

        // If sum is negative, then update it to zero - Discarding that negative
        // sub-array
        if (current_sum < 0) current_sum = 0;
    }

    return max_sum;
}

int main(int argc, char const *argv[]) {
    vector<int> list = {-5, -4, -6, -1, -4, -10};

    cout << largestSubArraySum(list) << endl;

    return 0;
}

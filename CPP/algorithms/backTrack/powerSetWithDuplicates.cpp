/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets.

Return the solution in ascending order.

Sample Input:   [1,2,2]
Sample Output:  [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/

#include <iostream>
#include <set>

using namespace std;

void printPowerSet(set<vector<int>> &final_result) {
    for (auto element : final_result) {
        for (auto ele : element) {
            cout << ele << "\t";
        }
        cout << endl;
    }
}

// Using set to avoid duplicate entries
void getPowerSet(vector<int> arr, int index, vector<int> &answer, set<vector<int>> &final_result) {
    // Base condition
    if (index == arr.size()) {
        vector<int> sorted_vector = answer;
        sort(sorted_vector.begin(), sorted_vector.end());
        final_result.insert(sorted_vector);
        return;
    }
    // Make choices
    // Generate subsets with the index element
    answer.push_back(arr[index]);
    getPowerSet(arr, index + 1, answer, final_result);

    // Generate subsets without the index element
    answer.pop_back();
    getPowerSet(arr, index + 1, answer, final_result);
}

int main(int argc, char const *argv[]) {
    vector<int> arr = {4, 4, 4, 1, 4};
    set<vector<int>> result;
    vector<int> answer;

    getPowerSet(arr, 0, answer, result);

    printPowerSet(result);

    return 0;
}

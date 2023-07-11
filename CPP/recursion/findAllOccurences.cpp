#include <iostream>

using namespace std;

vector<int> findAllOccurences(int k, vector<int> v, int current_index=0){

    // Base condition
    if (v.size() <= 0) {
        return {};
    }
    // Slice the vector
    vector<int> slice (v.begin()+1, v.end());

    // Assume recursion will solve this
    vector<int> result = findAllOccurences(k, slice,current_index+1);

    if (v[0] == k) {
        // During unwinding insert in front of result vector
        result.insert(result.begin(),current_index);
    }

    return result;
}



int main() {
    vector<int> arr = {3,3,3,3,1,2,3,2,1,7,4,7};
    vector<int> result = findAllOccurences(7,arr);

    // Print the indexes at which 'k' is present
    for (int index: result) {
        cout << index << "\t";
    }
    cout << endl;
    return 0;
}


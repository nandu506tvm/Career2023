#include <iostream>
#include <vector>

using namespace std;

// Brute Force approach
void printSubArray(vector<int> list) {
    int length = list.size();

    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            // Print all elements from i to j
            for (int k = i; k <= j; k++) {
                cout << list[k] << "\t";
            }
            cout << endl;
        }
    }
}

int main(int argc, char const *argv[]) {
    vector<int> list = {1, 2, 3, 4};
    printSubArray(list);

    return 0;
}

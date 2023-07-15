#include <iostream>
#include <vector>

using namespace std;

// Xor of same numbers will be zero. we will use that property
int FindUniqueElement(vector<int> v) {
    int result = 0;
    for (int element : v) {
        result = result ^ element;
    }
    return result;
}

int main() {
    vector<int> vect = {1, 2, 3, 1, 4, 2, 3, 5, 7, 7, 5};
    cout << FindUniqueElement(vect) << endl;

    return 0;
}

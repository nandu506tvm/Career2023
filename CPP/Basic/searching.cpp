#include <iostream>

using namespace std;

int main() {
    vector <int> arr = {1,2,3,4,5,6,7,8};
    if (binary_search(arr.begin(), arr.end(), 7)) {
        cout << "Element found" << endl;
    }
    else {
        cout << "Not Found" << endl;
    }

    return 0;
}


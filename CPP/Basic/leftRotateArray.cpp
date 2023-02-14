#include <iostream>
#include <vector>

using namespace std;

vector<int> rotateLeft(int d, vector<int> arr) {
    vector <int> revArray = arr;
    int temp = 0;
    unsigned int vecSize = arr.size();
    for (int i=0; i < vecSize; i++) {
        temp = i -d;
        if (temp <0) {
            revArray[vecSize + temp] = arr[i];
        }
        else {
            revArray[temp] = arr[i];
        }
    }
    return revArray;
}

int main(int argc, char const *argv[]) {

    vector<int> arr;
    int rotateCount = 4;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    vector<int> result = rotateLeft(rotateCount, arr);

    for (int i=0; i< 5; i++)
    {
        cout << result[i] << "\t";
    }
    cout << endl;

    return 0;
}


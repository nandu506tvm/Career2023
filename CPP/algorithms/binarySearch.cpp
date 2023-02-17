#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector <int> &vect, int leftIndex, int rightIndex, int key)
{
    bool isElementPresent = false;

    //Base condition
    if (leftIndex > rightIndex) return false;

    int mid = (leftIndex + rightIndex)/2;

    // Check if key is present at mid
    if (vect[mid] == key ) {return true;}

    // Check left array if key is less than value at index 'mid'
    else if (key < vect[mid])
    {
        isElementPresent = binarySearch(vect, leftIndex, mid-1, key);
    }

    // Else check right array
    else
    {
        isElementPresent = binarySearch(vect, mid+1, rightIndex, key);
    }

    return isElementPresent;
}

int main(int argc, char const *argv[]) {

    vector <int> vect;
    int key = 0;

    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(50);
    vect.push_back(70);
    vect.push_back(77);
    vect.push_back(80);
    vect.push_back(100);

    cout << "Enter element to be searched: ";
    cin >> key;

    bool isElementPresent = binarySearch(vect, 0,vect.size(), key);
    if (isElementPresent) 
    {
        cout << "Element Found" << endl;
    }
    else
    {
        cout << "Failed to find element" << endl;
    }

    return 0;
}


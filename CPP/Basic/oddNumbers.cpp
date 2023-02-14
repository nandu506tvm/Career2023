/*
 * Naive solution takes O(n) time
 * We can reduce that to constant time - O(1)
 * Calculate numbers between low and high, N = (high-low)+1
 * If N is even, then Number of Oddnumbers = N/2
 * If Low/high is odd, then Number of Oddnumbers = (N/2)+1
 * Else Number of Oddnumbers = N/2
 * */


#include <iostream>

using namespace std;

int getOddNumCount(int low, int high) {
    int Numbers = (high-low)+1;
    if (Numbers%2 == 0) {
        return (Numbers/2);
    }
    else if ((low%2 != 0) || (high%2 !=0)) {
        return ((Numbers/2)+1);
    }
    return (Numbers/2);
}

int main(int argc, char const *argv[]) {

    int low,high = 0;
    cout << "Enter Low: ";
    cin >> low;
    cout << "Enter High: ";
    cin >> high;

    cout << "Number of Odd Numbers: " << getOddNumCount(low,high) << endl;
    
    return 0;
}


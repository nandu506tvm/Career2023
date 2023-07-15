#include <iostream>

using namespace std;

int CountSetBits(int number) {
    int bit_mask = 1;
    int sum = 0;

    while (number != 0) {
        int right_bit = number & bit_mask;
        sum += right_bit;
        number = number >> 1;
    }

    return sum;
}

// This new hack works because on each iteration we are removing the last set
// bit. Number of times the loop iterates will give you the number of set bits.
int CountSetBitHack(int number) {
    int sum = 0;

    while (number > 0) {
        number = number & (number - 1);
        sum++;
    }

    return sum;
}

int main() {
    int number = 0;

    cout << "Enter a number: ";
    cin >> number;

    cout << CountSetBits(number) << endl;

    return 0;
}

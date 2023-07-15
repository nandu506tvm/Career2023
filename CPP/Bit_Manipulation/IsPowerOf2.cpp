#include <iostream>

using namespace std;

// Numbers which are power of 2, have one and only one bit set in binary
// representation. The position of the bit that is set will give the exponent of
// 2 that make that number.
bool IsPowerOfTwo(int number) {
    int set_bit_count = 0;
    // Bit at at this position is set
    while (number > 0) {
        if (number & 1) {
            set_bit_count++;
        }
        number >>= 1;
    }
    if (set_bit_count > 1) {
        return false;
    }
    return true;
}

bool EasyWay(int number) {
    bool result = (number & (number - 1)) ? false : true;
    return result;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << IsPowerOfTwo(number) << endl;
    cout << EasyWay(number) << endl;
    return 0;
}

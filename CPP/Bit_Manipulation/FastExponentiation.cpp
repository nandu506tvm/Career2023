#include <iostream>

using namespace std;

/* A given number N will have atmost Log (N) number of set bits
 * For eg: binary of 5 is 000101. Here number of set bits is 2 which is < log (5)
 * */


// Fast exponentiation is a way to calculate the power of a number say 5^2
// Since we have atmost log N bits in exponent, this algorithm take O(Log N)
int FastExponentiation(int base, int exponent) {
    int result = 1;

    // Iterate over the bits of the exponent
    while (exponent > 0) {
        // LSB is set
        if (exponent & 1) {
            result = result * base;
        }

        // when going for next iteration keep squaring the base
        base = base * base;

        // keep moving the exponent to the right
        exponent = exponent >> 1;
    }
    return result;
}

int main() {

    cout << FastExponentiation(5,3) << endl;

    return 0;
}


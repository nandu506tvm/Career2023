#include <iostream>

using namespace std;

// Here we need to calculate (base^exponent) % mod
int ModularExponentiation(int base, int exponent, int mod) {
    int result = 1;

    // Code for fast exponentiation
    while (exponent > 0) {
        // LSB is set
        if (exponent & 1) {
            result = (result * base) % mod;
        }
        // Square the base and then take the mod for next iteration
        base = (base * base) % mod;
        // Left shift the exponent
        exponent >>= 1;
    }
    return result;
}

int main() {
    cout << ModularExponentiation(2, 223, 353) << endl;
    return 0;
}

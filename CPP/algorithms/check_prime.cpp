#include <iostream>

using namespace std;

bool is_prime(int number) {
    int square_root = sqrt(number);
    int factors_count = 0;

    for (int i = 1; i <= square_root; ++i) {
        if (number % i == 0) {
            factors_count++;
            if (number / i != i) {
                factors_count++;
            }
        }
    }
    if (factors_count > 2) {
        return false;
    }
    return true;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << is_prime(number) << endl;
    return 0;
}
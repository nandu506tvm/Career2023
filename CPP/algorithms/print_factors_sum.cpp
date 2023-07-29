#include <iostream>

using namespace std;

int get_factors_sum(int number) {
    int factors_sum = 0;
    int square_root = sqrt(number);

    for (int i = 1; i <= square_root; ++i) {
        if (number % i == 0) {  // Prime check
            factors_sum += i;
            if (number / i != i) {  // To avoid square root getting counted twice as a factor
                factors_sum += number / i;
            }
        }
    }

    return factors_sum;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << get_factors_sum(number) << endl;
}

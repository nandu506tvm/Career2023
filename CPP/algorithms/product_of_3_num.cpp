#include <iostream>

using namespace std;

// Find a,b,c such that a*b*c = n such that a,b,c are distinct and (a,b,c) > 1
// Soln: Use prime factorization.
void find_numbers(int number) {
    int main_num = number;
    int a, b, c = 0;
    // Find a
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            a = i;
            break;
        }
    }
    // b*c = n/a;
    number /= a;

    // Find b,c
    for (b = a + 1; b * b <= number; ++b) {
        if (number % b == 0) {
            c = number / b;
            if (c <= b) {  // what if c is equal to zero or 1. set c to zero in that case
                c = 0;
            }
            break;
        }
    }

    // Check if soln is valid
    if (a * b * c == main_num) {
        cout << "Yes" << endl;
        cout << a << "\t" << b << "\t" << c << endl;
    } else {
        cout << "No" << endl;
        cout << a << "\t" << b << "\t" << c << endl;
    }
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    find_numbers(number);

    return 0;
}

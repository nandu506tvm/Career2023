/*
 * Find all primes within range L,R
 * Constraints: (L,R >= 10^8) but (R-L <= 10^6)
 * Here normal sieve wont work bcoz max global array size is 10^8
 * so we use segmented sieve here.
 */

#include <iostream>

using namespace std;

vector<int> generate_prime(int num) {
    vector<int> result;
    vector<bool> prime_list(num + 1, true);

    prime_list[0] = prime_list[1] = false;

    // Sieve algorithm
    for (int i = 2; i <= num; ++i) {
        if (prime_list[i]) {
            result.push_back(i);
            for (int j = 2 * i; j <= num; j += i) {
                prime_list[j] = false;
            }
        }
    }
    return result;
}

int main() {
    int left, right = 0;
    cout << "Enter left range: ";
    cin >> left;
    cout << "Enter right range: ";
    cin >> right;

    // Step1: Get list of all primes from 2 to sqrt(right)
    vector<int> primes = generate_prime(sqrt(right));

    // Step2: create a vector with size (R-L + 1)
    vector<bool> final_result(right - left + 1, true);

    // Mark all multiple of primes computed in step1 within [left,right] as false in 'final_result'.
    for (int prime : primes) {
        // Find the smallest multiple within [left, right]
        int smallest_multiple = (left / prime) * prime;
        // resultant value less than 'left' due to integer division.
        // Add 'prime' to get the multiple within [left, right]
        if (smallest_multiple < left) {
            smallest_multiple += prime;
        }

        // Find all multiples from 'smallest_multiple' till 'right'
        // NOTE: Array shifting needed while updating
        for (int i = smallest_multiple; i <= right; i += prime) {
            final_result[i - left] = false;
        }

        //  There maybe a case where smallest_multiple itself is prime number
        // Since we marked it as false in previous step, re-mark it as true
        if (smallest_multiple == prime) {
            final_result[smallest_multiple - left] = true;
        }
    }

    // Print the result
    for (int i = 0; i <= right - left + 1; i++) {
        if (final_result[i]) {
            cout << i + left << "\t";
        }
    }
    cout << endl;

    return 0;
}
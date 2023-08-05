/* We can use sieve algorithm to find out prime numbers within a range (pre-compute).
*  Assume all numbers in that range is prime. Then walk through the list.
*  If a number is marked as prime, then find the multiples of that number.
*  Set the multiple to false, since those cannot be prime.
*  We will have a final list with prime numbers marked as true.
*/
#include <iostream>

using namespace std;

const int N = 100;

vector<int> lowest_prime(N, 0), highest_prime(N, 0);

// Time complexity: N(log(log N))
// https://www.youtube.com/watch?v=pKvGYOnO9Ao&t=524s
void create_sieve(vector<bool> &sieve_list) {
    for (int i = 2; i < N; ++i) {
        if (sieve_list[i]) { 
            // Find and mark all multiples of i as 'not prime'
            for (int j = 2*i; j < N; j+= i) {
                sieve_list[j] = false;
                // Below code is only required if we hve to find lowest/highest prime
                highest_prime[j] = i;
                if (lowest_prime[j] == 0) {
                    lowest_prime[j] = i;
                }
            }
        }
    }
}

int main() {
    vector<bool> sieve_list(N, true);

    // Mark 1 and zero as not prime
    sieve_list[0] = sieve_list[1] = false;
    create_sieve(sieve_list);

    for(auto element: sieve_list) {
        cout << element << endl;
    } 
    return 0;
}
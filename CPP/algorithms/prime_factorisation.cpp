#include <iostream>

using namespace std;

// The smallest divisor of any number will be a prime number
vector<int> get_prime_factors(int number) {
    vector<int> prime_factors;
    int divisor = 2;
    while (number > 1)
    {
        if (number % divisor == 0) {
            prime_factors.push_back(divisor);
            number = number / divisor;
            continue;
        }
        divisor += 1;
    }
    
    return prime_factors;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    vector<int> prime_factors = get_prime_factors(number);

    for (auto element: prime_factors) {
        cout << element << "\t";
    }
    cout << endl;

    return 0;
}
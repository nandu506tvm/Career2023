#include <iostream>

using namespace std;

int find_gcd(pair<int, int> numbers) {
    int reminder = 0;
    while (numbers.second != 0) {
        reminder = numbers.first % numbers.second;
        numbers.first = numbers.second;
        numbers.second = reminder;
    }
    return numbers.first;
}

int main(int argc, char const *argv[]) {
    pair<int, int> number_pair;
    cout << "Enter first number: ";
    cin >> number_pair.first;
    cout << "Enter second number: ";
    cin >> number_pair.second;
    cout << "GCD is: " << find_gcd(number_pair) << endl;
    return 0;
}

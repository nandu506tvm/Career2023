#include <iostream>

using namespace std;

int power(int x, int k) {
    int result = 1;

    // Base condition
    if (k == 1) return x;

    // Induction hypothesis
    int temp = power(x, k - 1);

    // Final calculation
    result = x * temp;

    return result;
}

int main(int argc, char const *argv[]) {
    int x, k;
    cout << "Enter value of x: ";
    cin >> x;
    cout << "Enter value of K: ";
    cin >> k;
    cout << power(x, k) << endl;

    return 0;
}

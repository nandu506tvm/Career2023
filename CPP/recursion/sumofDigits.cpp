#include <iostream>
#include <string>

using namespace std;

int superDigit(string S, int k) {
    int result = 0;

    // Base condition
    if (S.length() == 1) return stoi(S);

    unsigned long long N = stoll(S);
    // Assume recursion will calculate other digits sum
    // Note that we are passing 1 as k as we have to multiply the final result
    // with k only once
    int subPrblmSum = superDigit(to_string(N / 10), 1);

    // Final calculation
    // We are multiplying by k that is if N is 148 and k is 3, then result =
    // (1+4+8) * 3 Therefore result = 13*3 = 39
    result = ((N % 10) + subPrblmSum) * k;

    // This is needed to calculate if result has more than two digits. That is
    // to add digits of 39
    if (result % 10 != result) {
        result = superDigit(to_string(result), 1);
    }

    return result;
}

int main(int argc, char const *argv[]) {
    string N = "";
    int K = 0;
    cout << "Enter string: ";
    cin >> N;
    cout << "Enter Value of K: ";
    cin >> K;
    cout << superDigit(N, K) << endl;

    return 0;
}

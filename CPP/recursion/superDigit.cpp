#include <iostream>
#include <string>

using namespace std;


int superDigit(string S, int k)
{
    long result = 0;

    // Base condition 
    if (S.length() == 1 ) return stoi(S);

    // Iterate through each char in string and convert it into int
    for (char &c: S) {
        result += c - 48;
    }

    result *= k;

    // This is needed to calculate if result has more than two digit.
    if (result%10 != result) {
        result = superDigit(to_string(result),1);
    }

    return result;
}

int main(int argc, char const *argv[]) {

    string N = "";
    int K = 0;
    cout << "Enter string: ";
    cin >>  N;
    cout << "Enter Value of K: ";
    cin >> K;
    cout << superDigit(N,K) << endl;
    
    return 0;
}


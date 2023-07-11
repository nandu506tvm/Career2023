#include <iostream>
#include <string>

using namespace std;

vector<string> arr_map = {"zero ", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};

// Covert individual digits in 'num' to string format
string printSpell(int num) {

    // Base condition: single digit
    if (num/10 <= 0) {
        return arr_map[num]; 
    }

    // Assume recurion will solve this
    string out = printSpell(num/10);

    // take the last digit, covert it into string and append to 'out'
    out.append(arr_map[num%10]);

    return out;
}

int main() {
    int a = 0;
    cout << "Enter a number: ";
    cin >> a;
    cout << printSpell(a) << endl;
    return 0;
}


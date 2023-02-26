#include <iostream>

using namespace std;

bool checkPalindrome(string str, int start, int end) {
    bool result = false;

    // Base condition
    if (start == end) return true;

    // Induction hypothesis
    if (str[start] == str [end]) {
        result = checkPalindrome(str,start+1, end-1);
    }
    else {
        result = false;
    }

    return result;
}

int main(int argc, char const *argv[]) {

    string str = "";
    cout << "Enter string to be checked: ";
    cin >> str;
    if (checkPalindrome(str, 0, str.length()-1)) {
        cout << "String is a palindrome" << endl;
    }
    else {
        cout << "String is not a palindrome " << endl;
    }
    
    return 0;
}


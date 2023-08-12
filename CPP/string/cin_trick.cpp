#include <iostream>

using namespace std;

int main() {
    int number = 0;
    cout << "Enter Number: ";
    cin >> number;

    // Without this next getline won't prompt for input.
    // '\n' from previous cin will be still in buffer.
    // Clear it first
    cin.ignore();

    // Now read a string
    string str;
    getline(cin, str);

    cout << "Number is: " << number << endl;
    cout << "String is: " << str << endl;

    return 0;
}
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int reverseNumber(int number)
{
    int reversed_num = 0;
    // Simple prblm is number having one digit only
    // In that case return the number itself
    if (number % 10 == number)
    {
        return number;
    }

    // Assum recursion will reverse other digits
    reversed_num = reverseNumber(number/10);

    // Do final calcualtion assuming other digits are already reversed
    // concatenate reversed_num + reminder;
    int reminder = number%10;

    // Convert to string and do concatenation
    string s1 = to_string(reminder);
    string s2 = to_string(reversed_num);
    string s = s1 + s2;

    return stoi(s);
}

int main(int argc, char const *argv[]) 
{
    int num = 0;
    cout << "Enter a number: ";
    cin >> num;
    cout << reverseNumber(num) << endl;
    
    return 0;
}


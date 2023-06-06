#include <iostream>

using namespace std;

int get_bit_at_i(int num, int i)
{
    // Left shift (i-1) time so that bit at position 'i' is set
    int bit_mask = 1 << (i-1);

    // Now perform bitwise '&' to check if that bit is set or not in 'num'
    if ((num & bit_mask) == 0) return 0;

    return 1;
}

int main() 
{
    int number = 5;
    int i = 1;
    cout << "Enter a number: ";
    cin >> i;

    // find and return the bit at  ith position
    cout << get_bit_at_i(number, i) << endl;
    
    return 0;
}


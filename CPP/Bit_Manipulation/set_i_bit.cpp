#include <iostream>

using namespace std;

int set_bit_at_i(int num, int i)
{
    // left shift (i-1) time to set the i-th bit of mask to 1
    int bit_mask = 1 << (i-1);

    // Now do logical 'OR' to set the i-th bit
    return (num | bit_mask);
}

int main() 
{
    int number = 5;
    int i = 1;
    cout << "Enter a number: ";
    cin >> i;

    // find and set the bit at  ith position
    cout << set_bit_at_i(number, i) << endl;
    
    return 0;
}


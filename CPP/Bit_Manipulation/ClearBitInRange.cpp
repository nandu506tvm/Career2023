#include <iostream>

using namespace std;

void ClearBitInRange(int &number, int i, int j) {
  // TO create bit mask here we need to perform some manipulation
  int mask_a = (~0) << j;

  // This will give a mask with the first i bits (from left) set to 1 and other bits set to 0
  int mask_b = (1 << i) -1;

  int bit_mask = mask_a | mask_b;

  number = number & bit_mask;
}

int main() {
  int number,i,j = 0;

  cout << "Enter a number: ";
  cin >> number;
  cout << "Enter left index: ";
  cin >> i;
  cout << "Enter right index: ";
  cin >> j;

  ClearBitInRange(number,i,j);

  cout << "New number is: " << number << endl;

  return 0;
}


#include <iostream>
using namespace std;

int main() {
  
  // Array initialisations
  int a[100]; // Allocate memory of (4 * 100) bytes of memory with garbage data
  int a[100] = {0}; // Initialize all array elements to zero
  int a[100] = {1,2,3}; // First 3 element will be 1,2,3 followed by zeroes.
  int a[] = {1,2,3}; // Size not mandatory since its initialized.
  
  string fruits[4] = {"Apple", "Mango", "Guava"};
}

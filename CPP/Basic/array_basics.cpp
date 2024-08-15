#include <iostream>
using namespace std;


// Here the output will be 8. 
// Bcoz function call stack will only have the address of first element here.
// Size of pointer is 8 bytes.
void print_size(int arr[]) {
	cout << "size of arr is: " << sizeof(arr) << endl;
}

// Reverse array by swapping
void reverseArray(int arr[], int n) {
	int start = 0;
	int end = n-1; // zero indexed
	
	while (start <= end) {
		swap(arr[start], arr[end]);
		start ++;
		end ++;
	}
}

int main() {
  
  // Array initialisations
  int a[100]; // Allocate memory of (4 * 100) bytes of memory with garbage data
  int a[100] = {0}; // Initialize all array elements to zero
  int a[100] = {1,2,3}; // First 3 element will be 1,2,3 followed by zeroes.
  int a[] = {1,2,3}; // Size not mandatory since its initialized.
  
  string fruits[4] = {"Apple", "Mango", "Guava"};\

  /*  Code to depict array pass by reference  */
  int arr[] = {1,2,3,4,5};
	
	// Calculate length of the array
	int size = sizeof(arr)/ size(int);
	
	// print the array size from main
	cout << "Array size is " << sizeof(arr) << endl;
	
	// Now call the print_array function and see
	print_size(arr);
	
	return 0;
}

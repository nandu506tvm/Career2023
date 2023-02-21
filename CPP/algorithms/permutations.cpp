#include <iostream>
#include <string>

using namespace std;

/*
 * Algorithm: On first iteration, startIndex will be zero.
 * Swap the character at startIndex with all the characters follwing startIndex using a loop.
 * Call recursion by incrementing startIndex by one to continue the procedure until startIndex = LastIndex.
 * Print the last level result as this will the final result.
 *
 *  Factorial time complexity - n!
 * */

void printPermutations(string word, int startIndex, int endIndex) {
    static int count = 1;
    if (startIndex == endIndex) {
        cout << count << ": "<< word << endl ;
        count ++;
    }
    for (int i=startIndex; i <= endIndex; i++) {
        swap(word[startIndex],word[i]);
        printPermutations(word, startIndex+1, endIndex);
    }
}

int main(int argc, char const *argv[])
{
    string str;
    cout << "Enter a string: ";
    cin >> str;
    printPermutations(str ,0,str.length()-1); 
    return 0;
}


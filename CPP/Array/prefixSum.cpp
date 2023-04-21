/*
 * Prefix sum algorithm is used when we have to perform 'm' number of queries on n-sized array.
 * Normal solution would take O(mn) time for completion of all the queries.
 * With prefix sum algorithm it can be done in O(n)
 * sum(elements till index i) = sum(elements till index (i-1)) + element at index i
 * If the sums are pre-computed in first pass, then answering range based queries will be easy !
 * */

#include <iostream>

using namespace std;

/*
 * For array of length n with all zero, add value k to elements between index a and b
 * Return the highest value in array after all the queries.
 * Each query element will have a,b,k values.
 * */

long arrayManipulation(int n, vector<vector<int>> queries) {
    long result = 0;
    int leftIndex, rightIndex, val = 0;
    vector <long> arr (n+1,0);
    unsigned int query = queries.size();
    
    // Iterate through the queries
    for (int i=0; i < query; i++) {
        leftIndex = queries[i][0];
        rightIndex = queries[i][1];
        val = queries[i][2];
        
    // Add val at leftindex and -ve of val at (rightindex +1)
    // Array is 1 indexed rather than zero.
        arr[leftIndex] += val;
        if (rightIndex+1 <= n){
            arr[rightIndex+1] += -val;
        }
    }
    
    // Use prefix sum algorithm to calcuate the final array after all queries
    result = arr[1];
    for (int i=2; i <= n; i++) {
        arr[i] = arr[i-1] + arr[i];
        if (result < arr[i]) result = arr[i];
    }
    
    
    return result;
}


int main(int argc, char const *argv[]) {

    vector<vector<int>> queries(m);
    long result = arrayManipulation(n, queries);

    return 0;
}


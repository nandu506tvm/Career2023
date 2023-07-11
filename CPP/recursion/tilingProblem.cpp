#include <iostream>

using namespace std;

// You are given N tiles of size 1 x M
// There is a floor of size N x M
// we have to cover the floor with tiles
// Find the number of ways we can do this,
// Tiles can be placed in both horizontal and vertical manner
int tilingProblem(int n,int m) {
    return n+m;
}

int main() {
    int n,m=0;

    cout << "Enter n,m: " ;
    cin >> n >> m;

    cout << tilingProblem(n,m) << endl;
    return 0;
}


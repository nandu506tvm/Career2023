#include <iostream>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    int temp1 = a.first + a.second;
    int temp2 = b.first + b.second;

    return temp1 < temp2;
}

// sorting vector of pairs with total of x,y coordinates
vector<pair<int, int>> sortCabs(vector<pair<int, int>> v) {
    // your code  goes here
    int length = v.size();

    sort(v.begin(), v.end(), compare);

    return v;
}

int main() { return 0; }

#include <iostream>

using namespace std;

int updateValue(int &value) { return (value + 1); }

int main(int argc, char const *argv[]) {
    int a = 10;
    cout << "Initial Value: " << a << endl;
    cout << "Final Value: " << updateValue(a) << endl;

    return 0;
}

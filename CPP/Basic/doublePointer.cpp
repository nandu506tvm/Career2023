#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int var = 10;
    int *pVar = &var;
    int **ppVar = &pVar;
  
    cout << "Value at &var: " << &var << endl;
    cout << "Value at pVar : " << pVar << endl;
    cout << "Value at *pVar : " << *pVar << endl;
    cout << "Value at &pvar is: " << &pVar << endl;
    cout << "+++++++ Now using double pointers ++++++ " << endl;
    cout << "Value at ppVar " << ppVar << endl;
    cout << "Value at *ppVar " << *ppVar << endl;
    cout << "Value at **ppVar " << **ppVar << endl;
    
    return 0;
}


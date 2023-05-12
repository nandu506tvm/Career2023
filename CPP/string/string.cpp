#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) 
{
    string str;
    
    // Third arg can also be given - delimiter character
    getline(cin, str);

    cout << str << endl;

    for (char character: str)
    {
        cout << character << ",";
    }
    cout << endl;
    
    return 0;
}


#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) 
{
    stack <string> books;

    books.push("Hello");
    books.push("World");
    books.push("Second");
    books.push("Time");

    while (!books.empty())
    {
        cout << books.top() << endl;
        books.pop();
    }
    
    return 0;
}


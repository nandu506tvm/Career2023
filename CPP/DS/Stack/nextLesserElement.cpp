#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Find the immediate next lesser element.
// Uses increasing monotonous stack, iterate backwards
vector<int> nextLesserElement(vector<int> list)
{
    stack<int> stck;
    int length = list.size();

    // Make sure to create result with length, else segfault will happen
    vector<int> result(length,-1);

    // Last element wont have any next lesser element
    stck.push(list[length-1]);

    for (int index=length-2; index>=0; index--)
    {
        // POP elements from stack if needed
        while((!stck.empty()) and (list[index] < stck.top()))
        {
            stck.pop();
        }

        // If stack empty then no next lesser element
        if (stck.empty())
        {
            stck.push(list[index]);
            continue;
        }

        // stack not empty, then present top will be our next lesser element
        result[index] = stck.top();
        stck.push(list[index]);

    }

    return result;
}


int main(int argc, char const *argv[]) 
{
    vector<int> result;
    vector<int> list = {2,1,4,3};

    result = nextLesserElement(list);

    for (int element: result)
    {
        cout << element << "\t";
    }
    cout << endl;
    
    return 0;
}


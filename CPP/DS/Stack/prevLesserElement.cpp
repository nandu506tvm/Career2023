#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Find the immediate previous lesser element.
vector<int> prevLesserElement(vector<int> list)
{
    stack<int> stck;
    int length = list.size();

    // Make sure to create result with length, else segfault will happen
    vector<int> result(length,-1);

    // Add the first element to stack
    stck.push(list[0]);

    for (int index=1; index<length; index++)
    {
        // POP elements from stack if needed
        while((!stck.empty()) and (list[index] < stck.top()))
        {
            stck.pop();
        }

        // If stack empty then no immediate previous lesser element
        if (stck.empty())
        {
            stck.push(list[index]);
            continue;
        }

        // stack not empty, then present top will be our previous lesser element
        result[index] = stck.top();
        stck.push(list[index]);

    }

    return result;
}


int main(int argc, char const *argv[]) 
{
    vector<int> result;
    vector<int> list = {2,1,3,4};

    result = prevLesserElement(list);

    for (int element: result)
    {
        cout << element << "\t";
    }
    cout << endl;
    
    return 0;
}


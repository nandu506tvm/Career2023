#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Finding next greater element - use decreasing monotonic stack
// Iterate array in reverse order
vector<int> nextGreaterElement(vector<int> v)
{
    int length = v.size();
    vector<int> result(length,-1);
    stack<int> stck;

    // There is no Next greater element for the  last element
    stck.push(length-1);

    for (int index=length-2; index >=0; index--)
    {
        while ((!stck.empty()) and (v[stck.top()] < v[index] ))
        {
            stck.pop();
        }
        // Stack empty means no next greater element, the result is already set to -1.
        // if not empty, then current stack top is the next greater element for the present index
        if (!stck.empty())
        {
            result[index] = v[stck.top()];
        }
        stck.push(index);
    }
    return result;
}

int main(int argc, char const *argv[]) 
{

    vector<int> elements = {4, 5, 2, 25};
    vector<int> result = nextGreaterElement(elements);

    for (int element: result)
    {
        cout << element << "\t";
    }
    cout << endl;
    
    return 0;
}


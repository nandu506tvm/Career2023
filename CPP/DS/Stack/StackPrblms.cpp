#include <iostream>
#include <stack>

using namespace std;

/* Inserts data at bottom of stack recursively */
void insertAtBottom (stack<int> &stck, int data)
{
    // Base condition
    if (stck.empty())
    {
        stck.push(data);
        return;
    }

    // Store the popped element to add it back
    int temp = stck.top();
    stck.pop();

    insertAtBottom(stck, data);

    // On unwinding add the popped element back
    stck.push(temp);
}

void reverseStack (stack<int> &stck)
{
    if (stck.empty())
    {
        return;
    }

}

void printStack (stack<int> stck)
{
    if (stck.empty())
    {
        cout << endl;
        return;
    }
    cout << stck.top() << "\t";
    stck.pop();

    printStack(stck);
}

int main(int argc, char const *argv[]) 
{
    stack<int> stck;
    stck.push(5);
    stck.push(6);
    stck.push(7);
    stck.push(8);

    printStack(stck);

    insertAtBottom(stck, 4);

    printStack(stck);

    // Reverse the stack and print
    reverseStack(stck);
    printStack(stck);
    
    return 0;
}


#include <iostream>
#include <queue>

using namespace std;


queue<int> interLeave(queue<int> q)
{
    queue<int> result;
    queue<int> temp;
    int middle = q.size()/2;
    int count = 1;

    // Move first set of elements till middle to another queue
    while(count <= middle)
    {
        temp.push(q.front());
        q.pop();
        count++;
    }

    // Now populate the result queue, adding elements from both queue
    while((!q.empty()) and (!temp.empty()))
    {
        result.push(temp.front());
        result.push(q.front());

        temp.pop();
        q.pop();
    }
    return result;
}

int main(int argc, char const *argv[]) 
{
    queue<int> q1;
    q1.push(11);
    q1.push(12);
    q1.push(13);
    q1.push(14);
    q1.push(15);
    q1.push(16);
    q1.push(17);
    q1.push(18);
    q1.push(19);
    q1.push(20);

    queue<int>result = interLeave(q1);

    while(!result.empty())
    {
        cout << result.front() << "\t";
        result.pop();
    }
    cout << endl;

    return 0;
}


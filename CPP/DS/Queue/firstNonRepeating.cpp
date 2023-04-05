#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;


/*********************************************************************
 *  We use 'MAP' to keep track of the character count when we iterate 
 *  We use 'Queue' to store elements we newly encounter on iteration.
 *  At each iteration, compare the front of Queue with MAP occurence.
 *  If the occurence of character is greater than one, then pop it.
 *  else if occurence of front of queue is one, then that's our result.
 * *******************************************************************/

vector<char> firstnonrepeating(vector<char> str)
{
    vector<char> result;
    queue<char> que;
    map<char,int> char_count;

    for (auto element: str)
    {
        // Increment the character count
        char_count[element] += 1;

        // If character is new, then push it onto Queue
        if (char_count[element] == 1)
        {
            que.push(element);
        }

        // Pop the front of Queue, if character count is greater than 1
        while((char_count[que.front()] > 1) and (!que.empty()))
        {
            que.pop();
        }

        // If queue is not empty, the front of queue will be the first non-reapting char
        if (!que.empty())
        {
            result.push_back(que.front());
        }
        // If queue is empty, then update the result as '0'
        else
        {
            result.push_back('0');
        }
    }

    // Printing the MAP key,values for debugging purpose
    for (auto pair: char_count)
    {
        cout << "{" << pair.first << ": " << pair.second << "}\n";
    }

    return result;
}

int main(int argc, char const *argv[]) 
{
    vector<char> list = {'a','a','a','a','a','a','a','a','a'};
    vector<char> result = firstnonrepeating(list);

    for (auto element: result)
    {
        cout << element << "\t";
    }
    cout << endl;

    return 0;
}


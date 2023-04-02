#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* *********************************************************************
* 
* Given a list containing heights of bars, find the largest contiguous 
* area of rectangle that can be constructed. Assume breadth to be 1 unit
*
************************************************************************/

// Brute force solution - O(n^2)
int bruteForceSoln(vector<int> hist)
{
    int length = hist.size();
    int result = -1;
    int area = 0;

    for (int index=0; index<length; index++)
    {
        int left_index = index-1;
        int right_index = index+1;
        int breadth = 1;

        // Explore left of current index
        while (left_index >= 0)
        {
            if (hist[left_index] < hist[index])
            {
                break;
            }
            breadth++;
            left_index--;
        }
        // Explore right of current index
        while (right_index < length)
        {
            if (hist[right_index] < hist[index])
            {
                break;
            }
            breadth++;
            right_index++;
        }

        // caculate and update the max area 
        area = hist[index]*breadth;
        if (area > result)
        {
            result = area;
        }
    }
    return result;
}

// Return previous lesser element index list
// index marked as -1 has no prev lesser element
vector<int> findPrevLess(vector<int> list, int length)
{
    vector<int> index_list(length,-1);
    stack<int> stck;

    // Add first element directly
    stck.push(0);

    for (int index=1; index<length; index++)
    {
        while((!stck.empty()) and (list[index] < list[stck.top()]))
        {
            stck.pop();
        }
        if (stck.empty())
        {
            stck.push(index);
            continue;
        }
        index_list[index] = stck.top();
        stck.push(index);

    }
    
    return index_list;
}

// Return next lesser element index list
// index marked as -1 has no next lesser element
vector<int> findNextLess(vector<int> list, int length)
{
    vector<int> index_list(length,-1);
    stack<int> stck;

    // Add last element
    stck.push(length-1);

    for (int index=length-2; index>=0; index--)
    {
        while((!stck.empty()) and (list[index] < list[stck.top()]))
        {
            stck.pop();
        }
        if (stck.empty())
        {
            stck.push(index);
            continue;
        }
        index_list[index] = stck.top();
        stck.push(index);
    }
    return index_list;
}

// Optimized solution - O(n)
int largestRectArea(vector<int> hist)
{
    int length = hist.size();
    int result = -1;
    int breadth = 1;
    int area = 1;

    // Find Immediate previous lesser element index list
    vector<int> prev_lesser_index_list = findPrevLess(hist, length);
    // Find Immediate next lesser element index list
    vector<int> next_lesser_index_list = findNextLess(hist, length);

    // breadth = (next_lesser_index - prev_lesser_index)-1 
    for (int index=0; index<length; index++)
    {
        if (next_lesser_index_list[index] == -1)
        {
            next_lesser_index_list[index] = length;
        }
        breadth = (next_lesser_index_list[index] - prev_lesser_index_list[index]) -1;
        area = hist[index] * breadth;

        // update max of present area,existing result
        result = max(area,result);

    }

    return result;
    
}

int main(int argc, char const *argv[]) 
{
    vector<int> list = {2,4};
    cout << "Largest rectangle area brute force: " << bruteForceSoln(list) << endl;
    cout << "Largest rectangle area optimized: " << largestRectArea(list) << endl;

    return 0;
}

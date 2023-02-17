#include <iostream>
#include <vector>

using namespace std;

/* Space complexity of O(m+n) 
 * Time complexity of O(m+n)
 * */
void mergeSortedLists(vector <int>&list1, vector <int>&list2, vector<int>&finalArr)
{
    int list1ptr = 0;
    int list2ptr = 0;
    int list1Size = list1.size();
    int list2Size = list2.size();

    while((list1ptr < list1Size) && (list2ptr < list2Size))
    {
        if (list1[list1ptr] < list2[list2ptr])
        {
            finalArr.push_back(list1[list1ptr]);
            list1ptr++;
        }
        else if (list1[list1ptr] > list2[list2ptr])
        {
            finalArr.push_back(list2[list2ptr]);
            list2ptr++;
        }
        else
        {
            finalArr.push_back(list1[list1ptr]);
            finalArr.push_back(list2[list2ptr]);
            list1ptr++;
            list2ptr++;
        }
    }

    if (list1ptr < list1Size)
    {
        for(int i=list1ptr; i < list1Size; i++)
        {
            finalArr.push_back(list1[i]);
        }
    }
    if (list2ptr < list2Size)
    {
        for (int j=list2ptr; j < list2Size; j++)
        {
            finalArr.push_back(list2[j]);
        }
    }
}

int main(int argc, char const *argv[]) {
    
    vector <int> vect1;
    vector <int> vect2;

    //Vector to store merged array
    vector <int> resultArr;

    //First list elements
    vect1.push_back(6);
    vect1.push_back(7);
    vect1.push_back(11);
    vect1.push_back(12);

    //Second list elements
    vect2.push_back(1);
    vect2.push_back(3);
    vect2.push_back(5);
    vect2.push_back(10);
    vect2.push_back(13);

    mergeSortedLists(vect1, vect2, resultArr);

    // Print the final merged list
    for(int &element: resultArr)
    {
        cout << element << "\t"; 
    }
    cout << endl;
    
    return 0;
}


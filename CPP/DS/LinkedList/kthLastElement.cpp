#include <iostream>
#include "LinkedList.h"

using namespace std;

int kthLastElement(Node *head,int k){
    Node *slow = head;
    Node *fast = head;
    int count = 1;
    // Move 'fast' pointer (K-1) times to right
    while(count != k)
    {
        fast = fast->next;
        count ++;
    }
    // Now move fast/slow pointer till next of fast is NULL
    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    // Slow will now point to kth last element, return this data
    return slow->data;
}


int main(int argc, char const *argv[]) 
{
    
    return 0;
}


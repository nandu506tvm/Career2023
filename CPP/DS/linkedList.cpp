/* When a class inherits another class, only public/protected variables/functions are shared between two classes.
 * Private variables/functions are only tied to that specific class.
 * The access-specifier mentioned while inheriting decides the visibility of those variables for subsequent inheritance.
 *
 */

#include <iostream>

using namespace std;

// Class declarations
class Node 
{
    public:
        int data;
        Node *next = NULL;
};

class LinkedList: private Node 
{
    Node *head = NULL;
    public:
        void addNode(int data);
        void deleteList();
        void printList();
        void getListLength();
};

// Class function definitions
void LinkedList :: addNode(int data) 
{
    Node *newNode = new Node;
    newNode -> data = data;
    if (head == NULL) 
    {
        head = newNode;
    }
    else 
    {
        Node *temp = head;
        while(temp->next != NULL) 
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}

void LinkedList :: printList() 
{
    Node *temp = head;
    while (temp != NULL) 
    {
        cout << temp -> data << " ->\t";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

void LinkedList :: deleteList()
{
    Node *temp = head;
    while (head != NULL)
    {
        temp = head;
        head = head -> next;
        delete temp;
    }
}

// Driver Code
int main(int argc, char const *argv[])   
{
    if (argc > 1) printf("No arguments allowed !\n");

    LinkedList *pList = new LinkedList();
    pList -> addNode(5);
    pList -> addNode(10);
    pList -> addNode(15);
    pList -> addNode(20);
    pList -> addNode(1);
    pList -> printList();
    pList -> deleteList();
    pList -> printList();
    delete pList;

    return 0;
}


#include <iostream>

#include "LinkedList.h"

using namespace std;

void LinkedList :: pushFront (int data, Node **head, Node **tail) 
{
    Node *new_node = new Node (data);
    if (*head == NULL) 
    {
	    *head = new_node;
	    *tail = new_node;
	    return;
    }

    new_node->next = *head;
    *head = new_node;
}

void LinkedList :: pushBack (int data, Node **head, Node **tail) 
{
    if (*head == NULL) 
    {
        pushFront (data, head, tail);
	    return;
    }

    Node *new_node = new Node (data);

    // Make the existing tail node point to new node
    (*tail)-> next = new_node;
    *tail = new_node;
}

void LinkedList :: printList (Node *current_node) 
{
    if (current_node == NULL) 
    {
        cout << endl;
        return;
    }

    cout << current_node->data << "\t";
    printList (current_node -> next);
}

int LinkedList :: findLength (Node *current_node) 
{
    if (current_node == NULL) return 0;

    return (1 + findLength (current_node->next));
}

bool LinkedList :: searchKey (Node *current_node, int key) 
{
    if (current_node == NULL) return false;
    if (current_node -> data == key) return true;
    return searchKey (current_node -> next, key);
}

void LinkedList :: popFront(Node **head, Node **tail) 
{
    if (*head == *tail)
    {
        delete *head;
        *tail = *head = NULL;
        return;
    }

    Node *current_head_next = (*head)->next;
    delete *head;
    *head = current_head_next;
   
}

void LinkedList :: popBack(Node **head, Node **tail)
{
    if (*head == *tail) 
    {
        delete *tail;
        *head = *tail = NULL;
        return;
    }

    Node *current_node = *head;
    while (current_node->next != *tail)
    {
        current_node = current_node->next;
    }
    delete *tail;

    // Update tail & set current_node->next to NULL
    *tail = current_node;
    (*tail)->next = NULL;

}

void LinkedList ::  Insert(int data, int pos, Node **head, Node **tail)
{
    int length = findLength(*head);

    if (pos < 1)
    {
        cout << "Invalid position" << endl;
    }
    else if (pos==1 || *head == NULL)
    {
        pushFront(data,head,tail);
    }
    else if (pos > length)
    {
        pushBack(data,head,tail);
    }
    else
    {
        int count = 1;
        Node *current_node = *head;
        Node *previous_node = *head;
        // walk and find position
        while (count != pos)
        {
            previous_node = current_node;
            current_node = current_node->next;
            count++;
        }
        Node *new_node = new Node(data);
        previous_node->next = new_node;
        new_node -> next = current_node;
    }
}

void LinkedList :: reverseList (Node **head, Node **tail)
{
    Node *current_node = *head;
    Node *previous_node = NULL;
    Node *next_node;
    *tail = *head;
    while(current_node != NULL)
    {
        // Store the next node
        next_node = current_node->next;
        // Point current_node->next to previous node
        current_node->next = previous_node;
        // increment current_node and previous_node
        previous_node = current_node;
        current_node = next_node;
    }
    *head = previous_node;
}

void LinkedList :: deleteList (Node **head, Node **tail) 
{
    if (*head == NULL) return;

    deleteList (&(*head)->next, tail);
    delete *head;

    *head = *tail = NULL;
}

int main () 
{
    LinkedList list;
    Node *head = NULL;
    Node *tail = NULL;
    int selection,data,position;
    while(true)
    {
        cout << endl;
        cout << "======================" << endl;
        cout << "1. Push at Front" << endl;
        cout << "2. Push at Back" << endl;
        cout << "3. Pop from Front" << endl;
        cout << "4. Pop from Back" << endl;
        cout << "5. Insert Element at middle" << endl;
        cout << "6: Print List" << endl;
        cout << "7: Reverse List" << endl;
        cout << "8: Search for Element" << endl;
        cout << "9: Clear screen" << endl;
        cout << "10: Quit" << endl;
        cout << "======================" << endl;
        cout << endl;
        cout << "Enter an option: ";
        cin >> selection;

        switch(selection)
        {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                list.pushFront(data,&head,&tail);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                list.pushBack(data,&head,&tail);
                break;
            case 3:
                list.popFront(&head,&tail);
                break;
            case 4:
                list.popBack(&head,&tail);
                break;
            case 5:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter position to insert: ";
                cin >> position;
                list.Insert(data,position,&head,&tail);
                break;
            case 6:
                cout << endl;
                list.printList(head);
                break;
            case 7:
                list.reverseList(&head,&tail);
                break;
            case 8:
                cout << "Enter element to be searched: ";
                cin >> data;
                list.searchKey(head,data);
                break;
            case 9:
                system("clear");
                break;
            case 10:
                goto exit_loop;
                break;
            default:
                cout << "Invalid option" << endl;
                goto exit_loop;
                break;
        }
    }
    exit_loop:list.deleteList(&head, &tail);
	
    return 0;
}

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

bool LinkedList :: searchkey (Node *current_node, int key) 
{
    if (current_node == NULL) return false;
    if (current_node -> data == key) return true;
    return searchkey (current_node -> next, key);
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
        cout << "1. pushFront" << endl;
        cout << "2. pushBack" << endl;
        cout << "3. popFront" << endl;
        cout << "4. popBack" << endl;
        cout << "5. Insert Element" << endl;
        cout << "6: Print List" << endl;
        cout << "7: quit" << endl;
        cout << "8: Clear screen" << endl;
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
                goto exit_loop;
                break;
            case 8:
                system("clear");
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

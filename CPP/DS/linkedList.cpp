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
	list.pushFront (300,&head, &tail);
	list.pushFront (50, &head, &tail);
	list.pushBack (700, &head, &tail);
	list.pushBack (800, &head, &tail);
    list.pushBack (1000, &head, &tail);
	list.printList (head);
    list.popFront(&head, &tail);
    list.popFront(&head, &tail);
    list.printList(head);
    list.popBack(&head, &tail);
    list.printList(head);
    list.Insert(1,2,&head,&tail);
    list.Insert(890,8,&head,&tail);
    list.printList(head);
    list.deleteList(&head, &tail);
    list.printList (head);
	return 0;
}

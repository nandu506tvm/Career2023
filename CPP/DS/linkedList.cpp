#include <fstream>
#include <iostream>
#include "linkedList.h"

using namespace std;

/* we use dynamic memory allocation so that
* memory wont be freed after function returns
*/
Node* linkedList :: pushFront (int data) {
	Node *new_node = new Node (data);

	/* List has no entry */
	if ( head == NULL ) {
		head = tail = new_node;
		return head;
	}

	/* List has entries */
	new_node->next = head;
	head = new_node;
	return head;
}

Node* linkedList :: pushBack (int data) {
	/* List has no entry */
	if ( tail == NULL ) {
		cout << "List is empty! " << endl;
		return NULL;
	}

	/* List has entries */
	Node *new_node = new Node ( data );
	tail->next = new_node;
	tail = new_node;
	return tail;
}

Node* linkedList :: Insert (int data, int position) {
	/* validate position */
	if (position == 1)
		return this -> pushFront (data);

	else if (position >= findLength (this -> head) )
		return this -> head;

	/* For inserting elements in between */
	Node *current_node = head;
	Node *prev_node = head;
	int count = 0;

	while ( current_node != NULL ) {
		count ++;

		if ( count == position ) break;

		prev_node = current_node;
		current_node = current_node->next;
	}

	/* Insert the new element */
	Node *new_node = new Node (data);
	prev_node->next = new_node;
	new_node->next = current_node;
	return this -> head;
}

void linkedList :: printList (Node *current_node ) {
	if (current_node == NULL) {cout << endl; return;}

	cout << current_node->data << "\t";
	printList (current_node -> next);
}

int linkedList :: findLength (Node *current_node) {
	if (current_node == NULL) return 0;

	return (1 + findLength (current_node->next) );
}

Node* linkedList :: popFront() {
	if (this -> head == NULL) {
		cout << "List is empty !" << endl;
		return this -> head;
	}

	// TODO - if list had only one element, set tail to NULL
	Node *current_head = this -> head;
	this -> head = current_head->next;
	delete current_head;
	return this -> head;
}

Node* linkedList :: popBack() {
	// List has no element
	if (this -> head == NULL)
		cout << "List is empty !" << endl;

	else if (this -> head == this -> tail) {
		delete tail;
		this -> head = this -> tail = NULL;

	} else {
		Node *current_node = this -> head;

		while (current_node -> next != tail)
			current_node = current_node -> next;

		delete tail;
		current_node -> next = NULL;
		this -> tail = current_node;
	}

	return this -> tail;
}

bool linkedList :: searchkey (Node *current_node, int key) {
	// Base condition
	if (current_node == NULL) return false;

	// Check if key is found
	if (current_node -> data == key) return true;

	return searchkey (current_node -> next, key);
}


void linkedList :: deleteList (Node *current_node) {
	if (current_node == NULL) {
		this -> head = NULL;
		this -> tail = NULL;
		return;
	}

	deleteList (current_node->next);
	delete current_node;
}

int main ( int argc, char const *argv[] ) {
	/* Change stdin/stdout to a file */
	freopen ( "input.txt", "r", stdin );
	freopen ( "output.txt", "w", stdout );
	linkedList list;
	Node *head = NULL;
	head = list.pushFront ( 10 );
	head = list.pushFront ( 30 );
	head = list.pushFront ( 50 );
	list.pushBack ( 100 );
	list.pushBack ( 200 );
	head = list.Insert (300,1);
	list.printList (head);
	head = list.Insert (400,4);
	list.printList (head);
	cout << list.searchkey (head, 400) << endl;
	cout << list.searchkey (head, 500) << endl;
	cout << list.searchkey (head, 300) << endl;
	list.popBack();
	head = list.popFront();
	list.popBack();
	head = list.popFront();
	list.printList (head);
	list.deleteList (head);
	return 0;
}

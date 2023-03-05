#ifndef LINKEDLIST
#define LINKEDLIST

class Node {
  private:
	int data;
	Node *next;

	// Initializer list
	Node ( int data ) : data (data),next (NULL) {}

	// Make linkedList a friend class to acess private members of 'Node'
	friend class linkedList;
};

class linkedList {
  private:
	Node *head;
	Node *tail;
  public:
	linkedList() : head (NULL),tail (NULL) {}
	Node* pushFront (int data);
	Node* pushBack (int data);
	Node* Insert (int data, int position);
	void printList (Node* current_node);
	int findLength (Node* current_node);
	void deleteList (Node *current_node);
	Node* popFront();
	Node* popBack ();
};

#endif
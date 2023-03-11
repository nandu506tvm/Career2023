class Node 
{
  public:
	int data;
	Node *next;

	// Initializer list
	Node ( int data ) : data (data),next (NULL) {}

};

class LinkedList 
{
  public:
	void pushFront (int data, Node **head, Node **tail);
	void pushBack (int data, Node **head, Node **tail );
	void Insert (int data, int pos, Node **head, Node **tail);
	void printList (Node *current_node);
	int findLength (Node *current_node);
	void deleteList (Node **head, Node **tail);
	bool searchkey (Node *current_node, int key);
	void popFront (Node **head, Node **tail);
	void popBack (Node **head, Node **tail);
};


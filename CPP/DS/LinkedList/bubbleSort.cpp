#include <iostream>

#include "LinkedList.h"

using namespace std;

Node *bubbleSortList(Node *head) {
    Node *current_node = head;
    Node *next_node = NULL;
    while (current_node->next != NULL) {
        next_node = current_node->next;
        // Run a loop from next element and compare it.
        while (next_node != NULL) {
            if (current_node->data > next_node->data) {
                swap(current_node->data, next_node->data);
            }
            next_node = next_node->next;
        }
        current_node = current_node->next;
    }
    return head;
}

int main(int argc, char const *argv[]) { return 0; }

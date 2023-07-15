// Implelment queue using circular array

#include <iostream>

#define MAX_SIZE 5

using namespace std;

class Queue {
   private:
    int arr[MAX_SIZE] = {0};
    int current_size = 0;
    int front = -1;
    int rear = -1;

   public:
    bool isQueueFull() { return current_size == MAX_SIZE; }
    bool isEmpty() { return current_size == 0; }
    void enqueue(int data) {
        if (isQueueFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = data;
        current_size++;
    }
    void dequeue() {
        if (isEmpty()) {
            return;
        }
        arr[front] = -1;
        current_size--;
        front = (front + 1) % MAX_SIZE;
    }
    void printArray() {
        for (int i = 0; i < MAX_SIZE; i++) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[]) {
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(10);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(7);
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.printArray();
    q1.enqueue(11);
    q1.enqueue(13);
    q1.enqueue(3);
    q1.enqueue(5);
    q1.dequeue();
    q1.enqueue(50);
    q1.enqueue(510);
    q1.dequeue();
    q1.printArray();

    return 0;
}

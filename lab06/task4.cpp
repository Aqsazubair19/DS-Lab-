#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL" << endl;
            return;
        }
        if (isEmpty())
            front = 0;
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        cout << value << " enqueued" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY" << endl;
            return;
        }
        cout << arr[front] << " dequeued" << endl;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY" << endl;
            return;
        }
        int i = front;
        cout << "Queue: ";
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(60);
    q.enqueue(70);
    q.display();
    return 0;
}

#include <iostream>
using namespace std;

#define SIZE 5   // maximum size of queue

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    
    bool isEmpty() {
        return (front == -1 || front > rear);
    }


    bool isFull() {
        return (rear == SIZE - 1);
    }


    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL. Cannot enqueue " << value << endl;
            return;
        }

        if (front == -1)   // first insertion
            front = 0;

        arr[++rear] = value;
        cout << value << " inserted into queue." << endl;
    }

    /
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY. Cannot dequeue." << endl;
            return;
        }

        cout << arr[front] << " removed from queue." << endl;
        front++;
    }


    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY." << endl;
            return;
        }

        cout << "Queue contents: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Check Empty/Full\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << (q.isEmpty() ? "Queue is EMPTY." : "Queue is NOT empty.") << endl;
            cout << (q.isFull() ? "Queue is FULL." : "Queue is NOT full.") << endl;
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

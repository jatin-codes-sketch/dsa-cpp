#include<iostream>
using namespace std;

class Queue {
public:
    int* arr;
    int capacity;
    int front;
    int rear;

    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void push(int val) {
        if ((rear + 1) % capacity == front) {
            cout << "Queue overflow!" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = val;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue underflow!" << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);

    while (!q.isEmpty()) {
        cout << q.peek() << " ";
        q.pop();
    }

    return 0;
}

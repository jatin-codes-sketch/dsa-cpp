#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue underflow!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.push(40);
    q.push(50);

    while (!q.isEmpty()) {
        cout << q.peek() << " ";
        q.pop();
    }

    return 0;
}

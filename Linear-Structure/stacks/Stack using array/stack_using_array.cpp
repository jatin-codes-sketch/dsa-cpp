#include<iostream>
using namespace std;

const int capacity = 5;

class Stack {
private:
    int arr[capacity];  // Array to store stack elements
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack is full. Cannot insert " << val << endl;
            return;
        }
        arr[++top] = val;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to peek." << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    s.pop();
    s.display();

    cout << "Top element: " << s.peek() << endl;

    return 0;
}

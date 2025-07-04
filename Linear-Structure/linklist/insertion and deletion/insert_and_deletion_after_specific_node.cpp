#include<iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) {
        this->value = val;
        next = nullptr;
    }
};

class Linklist {
public:
    Node* head;

    Linklist() {
        head = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAfterSpecificIdx(int val, int idx) {
        if (head == nullptr) return;

        Node* temp = head;

        while (temp != nullptr) {
            if (temp->value == idx) {
                Node* newnode = new Node(val);
                newnode->next = temp->next;
                temp->next = newnode;
                return;  // Insert after first match
            }
            temp = temp->next;
        }
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Linklist list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    cout << "Original List: ";
    list.print();

    list.insertAfterSpecificIdx(25, 20);  // Insert 25 after node with value 20

    cout << "After Inserting 25 after 20: ";
    list.print();

    return 0;
}

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
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* reverse_Nodes_in_K_group(Node* head, int k) {
        if (head == nullptr) return head;

        Node* temp = head;
        int count = 0;

        while (temp != nullptr && count < k) {
            temp = temp->next;
            count++;
        }

        if (count < k) return head;

        Node* prevNode = reverse_Nodes_in_K_group(temp, k);

        temp = head;
        count = 0;
        while (temp != nullptr && count < k) {
            Node* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            count++;
        }

        return prevNode;
    }
};

int main() {
    Linklist list;
    for (int i = 1; i <= 10; i++)
        list.insert(i);

    cout << "Original List: ";
    list.display();

    int k = 3;
    list.head = list.reverse_Nodes_in_K_group(list.head, k);

    cout << "Reversed in groups of " << k << ": ";
    list.display();

    return 0;
}

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

class LinkList {
public:
    Node* head;
    
    LinkList() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printList(Node* node) {
        while (node != nullptr) {
            cout << node->value << " -> ";
            node = node->next;
        }
        cout << "NULL" << endl;
    }

    Node* swap_node_pair(Node* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        Node* first = head;
        Node* second = head->next;
        Node* prev = nullptr;
        
        while (first != nullptr && second != nullptr) {
            Node* third = second->next;
            second->next = first;
            first->next = third;
            
            if (prev != nullptr) {
                prev->next = second;
            } else {
                head = second;
            }
            
            prev = first;
            first = third;
            if (third != nullptr) {
                second = third->next;
            } else {
                second = nullptr;
            }
        }
        return head;
    }
};

int main() {
    LinkList list;
    
    // Add nodes to the list
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    
    cout << "Original list: ";
    list.printList(list.head);
    
    list.head = list.swap_node_pair(list.head);
    
    cout << "List after swapping pairs: ";
    list.printList(list.head);
    
    return 0;
}

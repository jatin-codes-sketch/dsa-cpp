#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int value): val(value), next(nullptr) {}
};

class Solution {
public:
    Node* reverse_linklist(Node* head, int left, int right) {
        if (!head || left == right) return head;

        Node* dummy = new Node(0);
        dummy->next = head;
        Node* prev = dummy;

        for (int i = 0; i < left - 1; i++) prev = prev->next;

        Node* curr = prev->next;
        for (int i = 0; i < right - left; i++) {
            Node* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy->next;
    }
};

// Helper to print the list
void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper to create list from array
Node* createList(initializer_list<int> vals) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int val : vals) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

int main() {
    Node* head = createList({1, 2, 3, 4, 5});
    Solution sol;
    Node* newHead = sol.reverse_linklist(head, 2, 4);

    printList(newHead); 

    return 0;
}

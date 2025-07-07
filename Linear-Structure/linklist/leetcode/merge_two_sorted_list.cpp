#include<iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    
    Node(int val){
        this->value = val;
        next = nullptr;
    }
};

class linkList {
public:
    Node* head;
    
    linkList(){
        head = nullptr;
    }

    // Merge two sorted linked lists recursively
    Node* mergeTwoSortedList(Node* head1, Node* head2) {
        // Base cases
        if (head1 == nullptr) return head2;
        if (head2 == nullptr) return head1;

        // Recursive merging
        if (head1->value <= head2->value) {
            head1->next = mergeTwoSortedList(head1->next, head2);
            return head1;
        } else {
            head2->next = mergeTwoSortedList(head1, head2->next);
            return head2;
        }
    }
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // First sorted list: 1 -> 3 -> 5
    Node* l1 = new Node(1);
    l1->next = new Node(3);
    l1->next->next = new Node(5);

    // Second sorted list: 2 -> 4 -> 6
    Node* l2 = new Node(2);
    l2->next = new Node(4);
    l2->next->next = new Node(6);

    linkList list;
    Node* mergedHead = list.mergeTwoSortedList(l1, l2);

    printList(mergedHead);

    return 0;
}

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int value) : val(value), next(nullptr) {}
};

class Solution {
public:
    Node* addTwoNumbers(Node* l1, Node* l2) {
        Node* head = l1;
        Node* prev = nullptr;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            if (l1 != nullptr) {
                l1->val = sum % 10;
                prev = l1;
                l1 = l1->next;
            } else {
                // l1 is shorter — attach new node to end of result
                prev->next = new Node(sum % 10);
                prev = prev->next;
            }

            if (l2 != nullptr)
                l2 = l2->next;
        }

        return head;
    }
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3); // 342

    Node* l2 = new Node(5);
    l2->next = new Node(6);
    l2->next->next = new Node(4); // 465

    Solution sol;
    Node* result = sol.addTwoNumbers(l1, l2); // 807 -> 7 -> 0 -> 8

    cout << "Result: ";
    printList(result);

    return 0;
}

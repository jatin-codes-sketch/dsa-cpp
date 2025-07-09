#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* child;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
        child = nullptr;
    }
};

// Function to flatten the multilevel doubly linked list
Node* flattenLinklist(Node* head) {
    if (head == nullptr) return head;

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->child != nullptr) {
            Node* next = temp->next;

            // Flatten the child list recursively
            temp->next = flattenLinklist(temp->child);
            temp->next->prev = temp;
            temp->child = nullptr;

            // Move to the tail of the flattened child list
            while (temp->next != nullptr) {
                temp = temp->next;
            }

            // Reconnect the saved next node
            temp->next = next;
            if (next != nullptr) next->prev = temp;
        }

        temp = temp->next;
    }

    return head;
}

// Function to print the list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to add node at the end
Node* addNode(Node* tail, int val) {
    Node* newNode = new Node(val);
    tail->next = newNode;
    newNode->prev = tail;
    return newNode;
}

// Sample usage
int main() {
    // Create main list: 1 - 2 - 3 - 4
    Node* head = new Node(1);
    Node* node2 = addNode(head, 2);
    Node* node3 = addNode(node2, 3);
    Node* node4 = addNode(node3, 4);

    // Create child list for node 2: 5 - 6
    Node* child1 = new Node(5);
    Node* child2 = addNode(child1, 6);
    node2->child = child1;

    // Create child list for node 6: 7 - 8
    Node* child3 = new Node(7);
    Node* child4 = addNode(child3, 8);
    child2->child = child3;

    cout << "Flattened list: ";
    Node* flatHead = flattenLinklist(head);
    printList(flatHead);

    return 0;
}

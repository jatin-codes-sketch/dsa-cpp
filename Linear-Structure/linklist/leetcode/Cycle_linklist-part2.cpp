#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    
    Node(int val){
        this->value=val;
        next=nullptr;
    }
};

class Linklist{
    public:
    Node* head;
    
    Linklist(){
        head=nullptr;
    }
    
    Node* linklistCycle(Node* head){
        Node* slow=head;
        Node* fast=head;
        bool isCycle=false;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                isCycle=true;
                break;
            }
        }
        
        if(!isCycle){
            return nullptr;
        }else{
            slow=head;
            
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
};

int main(){
    Linklist ll;
    ll.head = new Node(1);
    ll.head->next = new Node(2);
    ll.head->next->next = new Node(3);
    ll.head->next->next->next = ll.head; // Creating a cycle for testing
    Node* cycleStart = ll.linklistCycle(ll.head);
    if(cycleStart){
        cout << "Cycle detected in the linked list starting at node with value: " << cycleStart->value << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }
    // Clean up memory (not strictly necessary in this example, but good practice)
    Node* temp = ll.head;
    while(temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp;
        if (nextNode == ll.head) break; // Stop if we reach the cycle start
        temp = nextNode;
    }
    ll.head = nullptr; // Set head to nullptr after deletion
    // Note: In a real application, you would need to handle memory management more carefully,
    // especially if the linked list is more complex or has multiple cycles.
    // This example is simplified for demonstration purposes.
    return 0;
}
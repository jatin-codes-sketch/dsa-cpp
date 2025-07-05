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
    
    bool linklistCycle(Node* head){
        Node* slow=head;
        Node* fast=head;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
            
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Linklist ll;
    ll.head = new Node(1);
    ll.head->next = new Node(2);
    ll.head->next->next = new Node(3);
    ll.head->next->next->next = ll.head; // Creating a cycle for testing

    if(ll.linklistCycle(ll.head)){
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}
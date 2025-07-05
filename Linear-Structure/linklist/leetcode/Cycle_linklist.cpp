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
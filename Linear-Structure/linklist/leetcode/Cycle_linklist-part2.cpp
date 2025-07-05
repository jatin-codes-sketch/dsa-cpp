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
    return 0;
}
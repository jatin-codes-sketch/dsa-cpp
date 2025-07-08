#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* random;
    
    Node(int val) : value(val), next(nullptr), random(nullptr) {}
};

Node* copyList(Node* head){
    
    if(head==nullptr)return nullptr;
    
    Node* newHead=new Node(head->value);
    Node* oldtemp=head->next;
    Node* newtemp=newHead;
    
    
    
    unordered_map<Node*,Node*>m;
    
    
    while(oldtemp!=nullptr){
        Node* copyNode=new Node(oldtemp->value);
        m[oldtemp]=copyNode;
        newtemp->next=copyNode;
        
        oldtemp=oldtemp->next;
        newtemp=newtemp->next;
    }
    
    oldtemp=head;newtemp=newHead;
    while(oldtemp!=nullptr){
        newtemp->random=m[oldtemp->random];
        oldtemp=oldtemp->next;
        newtemp=newtemp->next;
    }
    
    return newHead;
}

int main(){
    return 0;
}
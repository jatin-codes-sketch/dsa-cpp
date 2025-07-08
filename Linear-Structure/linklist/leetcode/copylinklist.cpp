#include<iostream>
#include<unordered_map>
using namespace std;

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
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
    
    void insertAtbegining(int val){
        Node* newnode=new Node(val);
        newnode->next=head;
        head=newnode;
    }
    
    void deleteAtBegining(){
        if(head==nullptr)return;
        Node*temp=head;
        head=head->next;
        delete temp;
        temp=nullptr;
    }
};





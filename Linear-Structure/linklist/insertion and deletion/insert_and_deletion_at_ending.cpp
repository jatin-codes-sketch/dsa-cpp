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
    
    void insertAtEnding(int val){
        Node* newnode=new Node(val);
        if(head==nullptr){
            head=newnode;
        }else{
            Node* temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
        }
        temp->next=newnode;
    }
    
    void deleteAtEnding(){
        if(head==nullptr)return;
        if(head->next==nullptr){
            delete head;
            head=nullptr;
            return;
        }
        
        Node* temp=head;
        while(temp->next->next!=nullptr)temp=temp->next;
        delete temp->next;
        temp->next=nullptr;
    }
};



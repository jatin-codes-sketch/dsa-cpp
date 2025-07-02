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

int main(){
    Linklist ll;
    
    ll.insertAtbegining(10);
    ll.insertAtbegining(20);
    ll.insertAtbegining(30);
    
    cout<<"List after insertion at beginning: ";
    Node* temp=ll.head;
    while(temp){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
    ll.deleteAtBegining();
    
    cout<<"List after deletion at beginning: ";
    temp=ll.head;
    while(temp){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
    return 0;
}





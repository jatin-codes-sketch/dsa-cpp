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
    
    void insert(int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        head = newNode;
    } else {
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
    
    Node* Middle_of_linklist(){
        Node* slow=head;
        Node* fast=head;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

int main(){
    Linklist list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    Node* mid = list.Middle_of_linklist();
    if(mid != nullptr)
        cout << "Middle element: " << mid->value << endl;

    return 0;
}

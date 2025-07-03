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
    
    
    
    void insertBeforeAtNode(int val,int target){
        Node* newnode=new Node(val);
        if(head==nullptr)return;
        
        if(head->value==target){
            newnode->next=head;
            head=newnode;
            return;
        }
        
        Node* temp=head;
        while(temp->next!=nullptr && temp->next->value!=target)temp=temp->next;
        
        if(temp->next!=nullptr){
        newnode->next=temp->next;
        temp->next=newnode;
        }else{
            delete newnode;
        }
    }
    
    void deleteBeforeAtNode(int target){
        if(head==nullptr || head->value==target)return;
        
        if(head->next!=nullptr && head->next->value==target){
            Node* temp=head;
            head=head->next;
            delete temp;
            return;
        }
        
        Node* prev=head;
        Node* curr=head->next;
        
        while(curr->next!=nullptr && curr->next->value!=target){
            prev=curr;
            curr=curr->next;
        }
        
        if(curr->next!=nullptr){
            prev->next=curr->next;
            delete curr;
        }
        
    }
    
    void printList() {
    Node* temp = head;
    while (temp) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}
};

int main(){
    

    return 0;
}

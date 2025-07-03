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
    
    
    Node* reverseLinklist(Node* head){
        Node* prev=nullptr;
        Node* curr=head;
        
        while(curr!=nullptr){
            Node* nextTemp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextTemp;
        }
        return prev;
        
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
    
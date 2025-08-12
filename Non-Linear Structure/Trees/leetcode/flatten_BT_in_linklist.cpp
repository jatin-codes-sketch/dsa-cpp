#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int value;
    Node* left;
    Node* right;
    
    Node(int val):value(val),left(nullptr),right(nullptr){};
}

Node* nextRight=nullptr;
void flatten(Node* root){
    if(root==nullptr)return;
    
    flatten(root->right);
    flatten(root->left);
    
    root->left=nullptr;
    root->right=nextRight;
    nextRight=root;
}

int main(){
    return 0;
}
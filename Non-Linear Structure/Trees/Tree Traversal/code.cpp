#include<iostream>
#include<vector>
using namespace std; 

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    
    Node(int value){
        this->val=value;
        left=nullptr;
        right=nullptr;
    }
};

static int i=-1;
Node* buildTree(vector<int>&vec){
    i++;
    
    if(i>=vec.size() || vec[i]==-1)return nullptr;
    Node* root=new Node(vec[i]);
    root->left=buildTree(vec);
    root->right=buildTree(vec);
    return root;
}

void preOrder(Node* root){
    if(!root)return;
    
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(!root)return;
    
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(!root)return ;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

int main(){
    
    vector<int> vec = {2, 3, 4, -1, -1, 5, -1, -1, 3, -1, 4}; 
    
    Node* root=buildTree(vec);

    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    inOrder(root);
    
    return 0;
}
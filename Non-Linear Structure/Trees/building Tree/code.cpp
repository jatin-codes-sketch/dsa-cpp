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


int main(){
    
    vector<int> vec = {2, 3, 4, -1, -1, 5, -1, -1, 3, -1, 4}; 
    
    Node* root=buildTree(vec);
    
    return 0;
}
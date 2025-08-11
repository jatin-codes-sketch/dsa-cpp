#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x): val(x), left(nullptr), right(nullptr) {}
};

void helper(Node* curr,vector<int>&ans){
    while(curr!=nullptr){
        if(curr->left==nullptr){
            ans.push_back(curr->val);
            curr=curr->right;
        }else{
            Node* IP=curr->left;
            while(IP->right!=nullptr && IP->right!=curr){
                IP=IP->right;
            }
            if(IP->right==nullptr){
                IP->right=curr;
                curr=curr->left;
            }else{
                IP->right=nullptr;
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
}

vector<int> MorrisInorderTraversal(Node* root){
    vector<int>ans;
    Node* curr=root;
    helper(curr,ans);
    return ans;
}

int main(){
    Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    vector<int> res=MorrisInorderTraversal(root);
    for(int v:res) cout<<v<<" ";
    cout<<endl;
    return 0;
}

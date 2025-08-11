#include<iostream>
#include<vector>
using namespace std;

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
    return 0;
}
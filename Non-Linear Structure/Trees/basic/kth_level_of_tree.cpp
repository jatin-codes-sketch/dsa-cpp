#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int value) {
        this->val=value;
        left=nullptr;
        right=nullptr;
    }
};

void KthLevel(Node* root, int k) {
    if (root==nullptr) return;

    if (k==1) {
        cout<<root->val<<" ";
        return;
    }

    KthLevel(root->left, k-1);
    KthLevel(root->right, k-1);
}

int main() {
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    int k;
    cout<<"value of k: ";
    cin>>k;

    cout<<"Nodes at level " <<k<<":";
    KthLevel(root, k);
    cout<<endl;

    return 0;
}

#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* LowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (root == nullptr || root == p || root == q) return root;

    Node* leftNode = LowestCommonAncestor(root->left, p, q);
    Node* rightNode = LowestCommonAncestor(root->right, p, q);
   
    if (leftNode && rightNode)return root;
   
    return leftNode?leftNode:rightNode;
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Node* p = root->left;             
    Node* q = root->left->right->right; 

    Node* lca = LowestCommonAncestor(root, p, q);
    if (lca)
        cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}

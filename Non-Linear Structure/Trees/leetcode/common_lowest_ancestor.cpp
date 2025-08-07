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
    

    return 0;
}

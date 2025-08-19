#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

bool helper(Node* root, Node* minNode, Node* maxNode) {
    if (root == nullptr) return true;

    if (minNode != nullptr && root->val <= minNode->val) return false;
    if (maxNode != nullptr && root->val >= maxNode->val) return false;

    return helper(root->left, minNode, root) && helper(root->right, root, maxNode);
}

bool validateBST(Node* root) {
    return helper(root, nullptr, nullptr);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    cout << (validateBST(root) ? "Valid BST" : "Invalid BST") << endl;

    return 0;
}

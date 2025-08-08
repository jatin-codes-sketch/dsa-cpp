#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int transform_to_sum_tree(Node* root) {
    if (root == nullptr) return 0;

    int old_val = root->val;
    int leftSum = transform_to_sum_tree(root->left);
    int rightSum = transform_to_sum_tree(root->right);

    root->val = leftSum + rightSum;
    return root->val + old_val;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    cout << "before converting to Sum Tree:\n";
    inorder(root);
    cout << endl;

    transform_to_sum_tree(root);

    cout << "after converting to Sum Tree:\n";
    inorder(root);
    cout << endl;

    return 0;
}

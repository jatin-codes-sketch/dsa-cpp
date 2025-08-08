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

int transform_to_sum_tree(Node* root) {
    if (root == nullptr) return 0;

    int old_val = root->val;
    int leftSum = transform_to_sum_tree(root->left);
    int rightSum = transform_to_sum_tree(root->right);
    root->val = leftSum + rightSum;
    return old_val + root->val;
}

int main() {

    return 0;
}

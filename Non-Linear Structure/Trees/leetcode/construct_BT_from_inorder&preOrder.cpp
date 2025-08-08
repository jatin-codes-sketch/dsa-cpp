#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};



Node* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right) {
    if (left > right) return nullptr;

    Node* root = new Node(preorder[preIdx]);
    int inIdx = search(inorder, left, right, preorder[preIdx]);
    preIdx++;

    root->left = helper(preorder, inorder, preIdx, left, inIdx - 1);
    root->right = helper(preorder, inorder, preIdx, inIdx + 1, right);

    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIdx = 0;
    return helper(preorder, inorder, preIdx, 0, inorder.size() - 1);
}

void inorderPrint(Node* root) {
    if (root == nullptr) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {
    vector<int> preorder = {10, -2, 8, -4, 6, 7, 5};
    vector<int> inorder = {8, -2, -4, 10, 7, 6, 5};

    Node* root = buildTree(preorder, inorder);

    inorderPrint(root);
    cout << endl;

    return 0;
}

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

int midDiffBST(Node* root, Node*& prev) {
    if (root == nullptr) return INT_MAX;

    int ans = INT_MAX;

    // Left subtree
    ans = min(ans, midDiffBST(root->left, prev));

    // Current node difference
    if (prev != nullptr) {
        ans = min(ans, root->val - prev->val);
    }
    prev = root;

    // Right subtree
    ans = min(ans, midDiffBST(root->right, prev));

    return ans;
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Node* prev = nullptr;
    cout << midDiffBST(root, prev) << endl; 
}

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

void build(Node*& root, int data) {
    if (root == nullptr) {
        root = new Node(data);
        return;
    }

    if (data < root->value) {
        build(root->left, data);
    } else {
        build(root->right, data);
    }
}

Node* buildBTS(vector<int>& vec) {
    Node* root = nullptr;
    for (int val : vec) {
        build(root, val);
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

int main() {
    vector<int> vec = {5, 3, 7, 2, 4, 6, 8};
    Node* root = buildBTS(vec);
    inorder(root);
    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

Node* nextRight = nullptr;

void flatten(Node* root) {
    if (root == nullptr) return;
    flatten(root->right);
    flatten(root->left);
    root->left = nullptr;
    root->right = nextRight;
    nextRight = root;
}

void printRightList(Node* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << "\n";
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    flatten(root);
    printRightList(root);
}

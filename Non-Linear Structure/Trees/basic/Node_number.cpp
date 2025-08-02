#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        this->value = val;
        left = nullptr;
        right = nullptr;
    }
};

int i = -1;

Node* buildTree(vector<int>& vec) {
    i++;
    if (i >= vec.size() || vec[i] == -1) return nullptr;

    Node* root = new Node(vec[i]);
    root->left = buildTree(vec);
    root->right = buildTree(vec);

    return root;
}

int TreeNodeNum(Node* root) {
    if (root == nullptr) return 0;

    int leftSide = TreeNodeNum(root->left);
    int rightSide = TreeNodeNum(root->right);

    return leftSide + rightSide + 1;
}

int main() {
    vector<int> treeInput = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(treeInput);

    cout << "Number of nodes in the tree: " << TreeNodeNum(root) << endl;

    return 0;
}

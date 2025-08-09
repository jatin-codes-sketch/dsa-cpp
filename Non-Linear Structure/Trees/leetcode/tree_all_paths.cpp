#include <iostream>
#include<vector>
#include<string>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void allPaths(Node* root, string path, vector<string>& ans) {
    if (!root->left && !root->right) {
        ans.push_back(path);
        return;
    }
    if (root->left) allPaths(root->left, path + "->" + to_string(root->left->val), ans);
    if (root->right) allPaths(root->right, path + "->" + to_string(root->right->val), ans);
}

vector<string> binaryTreePaths(Node* root) {
    vector<string> ans;
    if (!root) return ans;
    allPaths(root, to_string(root->val), ans);
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    vector<string> paths = binaryTreePaths(root);
    for (auto& p : paths) cout << p << endl;
    return 0;
}

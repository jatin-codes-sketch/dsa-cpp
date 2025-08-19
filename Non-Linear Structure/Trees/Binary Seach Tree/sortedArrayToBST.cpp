#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

Node* helper(vector<int>& nums, int st, int end) {
    if (st > end) return nullptr;

    int mid = st + (end - st) / 2;
    Node* root = new Node(nums[mid]);
    root->left = helper(nums, st, mid - 1);
    root->right = helper(nums, mid + 1, end);
    return root;
}

Node* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
}


void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    Node* root = sortedArrayToBST(nums);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}

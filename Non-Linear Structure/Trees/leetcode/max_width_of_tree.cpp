#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxWidth(Node* root) {
    if (!root) return 0;
    queue<pair<Node*, unsigned long long>> q;
    q.push({root, 0});
    int maxWid = 0;
    
    
    while (!q.empty()) {
        int currLevelsize = q.size();
        unsigned long long first = q.front().second;
        unsigned long long last  = q.back().second;
        
        maxWid = max(maxWid, (int)(last - first + 1));
        
        for (int i = 0; i < currLevelsize; i++) {
            auto curr = q.front();
            q.pop();
            
            unsigned long long idx = curr.second - first;
            
            if (curr.first->left) {
                q.push({curr.first->left, idx * 2 + 1});
            }
            
            
            if (curr.first->right) {
                q.push({curr.first->right, idx * 2 + 2});
            }
        }
    }
    return maxWid;
}

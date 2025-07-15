#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> next_greater_element_I(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    unordered_map<int, int> m;

    for (int i = nums2.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= nums2[i]) {
            s.pop();
        }

        m[nums2[i]] = s.empty() ? -1 : s.top();
        s.push(nums2[i]);
    }

    for (int i = 0; i < nums1.size(); i++) {
        nums1[i] = m[nums1[i]];
    }

    return nums1;
}

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = next_greater_element_I(nums1, nums2);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

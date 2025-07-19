#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution{
    public:
    vector<int> nextGreaterElement(vector<int>&nums){
        stack<int>s;
        int n=nums.size();
        vector<int>ans(n,-1);
        
        for(int i=2*n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<=nums[i%n])s.pop();
            
            ans[i%n]=s.empty()?-1:nums[s.top()];
            s.push(i%n);
            
        }
        
        return ans;
        
        
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> res = sol.nextGreaterElement(nums);

    for (int val : res) {
        cout << val << " ";
    }

    return 0;
}
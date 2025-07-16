#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> previous_smaller_element(vector<int>&num){
    int n=num.size();
    vector<int>ans(n,0);
    stack<int>s;
    
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top()>=num[i])s.pop();
        
        if(s.empty()){
            ans[i]=-1;
        }else{
            ans[i]=s.top();
        }
        
        s.push(num[i]);
    }
    
    return ans;
}

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> res = previous_smaller_element(nums);
    for (int val : res) {
        cout << val << " ";
    }
    return 0;
}





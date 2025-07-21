#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int missingPositive(vector<int>nums){
    int n=nums.size();
    
    for(int i=0;i<n;i++){
        if(nums[i]<=0 || nums[i]>n){
            nums[i]=n+1;
        }
    }
    
    for(int i=0;i<n;i++){
        int val=abs(nums[i]);
        if(val <= n && nums[val - 1] > 0){
        nums[val-1]=-nums[val-1];
        }
    }
    
    for(int i=0;i<n;i++){
        if(nums[i]>0){
            return i+1;
        }
    }
    return n+1;
}

int main(){
    
    vector<int>nums={3,4,-1,1};
    
    int missingValue=missingPositive(nums);
    cout<<"the missing positive value: "<<missingValue;
    
    return 0;
}
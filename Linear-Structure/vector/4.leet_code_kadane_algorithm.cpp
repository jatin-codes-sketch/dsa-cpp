#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int kadane_algorithm(vector<int>&vec){
    int maxSum=0,curr=0;
    for(int i:vec){
        curr+=i;
        maxSum=max(curr,maxSum);
        
        if(curr<0)curr=0;
    }
    return maxSum;
}

int main(){
    vector<int>vec={-2,1,-1,4,-1,2,1,-5,4};
    cout<<kadane_algorithm(vec);
    
    return 0;
}
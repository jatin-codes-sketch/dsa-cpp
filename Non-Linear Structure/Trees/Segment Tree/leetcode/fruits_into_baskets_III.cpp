#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    void buildST(vector<int>&baskets,int i,int start,int end,vector<int>&tree){
        if(start==end){
            tree[i]=baskets[start];
        }else{
            int mid=start+(end-start)/2;
            buildST(baskets,2*i+1,start,mid,tree);
            buildST(baskets,2*i+2,mid+1,end,tree);
            
            tree[i]=tree[2*i+1]+tree[2*i+2];
        }
    }
    
    
    int fruitBaskets(vector<int>&fruits,vector<int>&baskets){
        int n = fruits.size();
        vector<int>tree(4*n,-1);
        
        buildST(baskets,0,0,n-1,tree);
        
    }
};


int main(){
    return 0;
}
// Online C++ compiler to run C++ program online
#include <iostream>
#include<unordered_map>
#include<vector>
#include<unordered_map>
using namespace std;

int subarray(vector<int>&arr,int target){
   int n=arr.size();
   vector<int>preSum(n,0);
   int count=0;
   
   preSum[0]=arr[0];
   for(int i=1;i<n;i++){
       preSum[i]=preSum[i-1]+arr[i];
   }
   
   unordered_map<int,int>m;
   for(int j=0;j<n;j++){
       if(preSum[j]==target)count++;
       
       int val=preSum[j]-target;
       if(m.find(val)!=m.end()){
           count+=m[val];
       }
       
       if(m.find(preSum[j])==m.end()){
           m[preSum[j]]=0;
       }
       m[preSum[j]]++;
   }
   return count;
    
}

int main() {
    

    return 0;
}
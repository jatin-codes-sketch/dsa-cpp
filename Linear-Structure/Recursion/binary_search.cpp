#include <iostream>
#include<vector>
using namespace std;

int BS(vector<int>&arr,int n,int target,int start,int end){
    if(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==target)return mid;
        if(arr[mid]>target)return BS(arr,n,target,start,mid-1);
        if(arr[mid<target])return BS(arr,n,target,mid+1,end);
    }
    return -2;
}

int binarySearch(vector<int>&arr,int n,int target){
    int start=0,end=n-1;
    
    return BS(arr,n,target,start,end);
}


int main() {
    vector<int>arr={2,3,4,5,6,7,9,11,12,13};
    int n=arr.size();
    int target=9;
    
    cout<<binarySearch(arr,n,target);
    
    
    
    
    return 0;
}
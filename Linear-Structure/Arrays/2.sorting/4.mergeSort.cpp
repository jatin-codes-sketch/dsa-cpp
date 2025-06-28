#include <iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr,int st,int mid,int end){
    
    vector<int>ans;
    int i=st,j=mid+1;
    while(i<=mid&&j<=end){
        if(arr[i]<=arr[j]){
            ans.push_back(arr[i]);
            i++;
        }else{
            ans.push_back(arr[j]);
            j++;
        }
        
    }
    
    while(i<=mid){
        ans.push_back(arr[i]);
        i++;
    }
    
    while(j<=end){
        ans.push_back(arr[j]);
        j++;
    }
    
    for(int idx=0;idx<ans.size();idx++){
        arr[idx+st]=ans[idx];
    }
    
}

void mergeSort(vector<int>&arr,int st,int end){
    
    if(st<end){
        int mid=st+(end-st)/2;
        
        mergeSort(arr,st,mid); // left
        mergeSort(arr,mid+1,end); //right
        
        merge(arr,st,mid,end);
        
    }
    
}


int main() {
    
    vector<int>arr={2,5,3,7,1};
    
    mergeSort(arr,0,arr.size()-1);
    
    for(int val:arr){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}
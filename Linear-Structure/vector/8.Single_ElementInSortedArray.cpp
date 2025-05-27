#include<iostream>
#include<vector>
using namespace std;

int SingleElementInSortedArray(vector<int>&vec){
    int n=vec.size();
    if(n==1)return vec[0];
    
    int start=0,end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        
        if(mid==0&&vec[0]!=vec[1])return vec[mid];
        if(mid==end&&vec[end]!=vec[end-1])return vec[end];
        
        if(vec[mid-1]!=vec[mid] && vec[mid]!=vec[mid+1])return vec[mid];
        
        if(mid%2==0){
            if(vec[mid-1]==vec[mid]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }else{
            if(vec[mid-1]==vec[mid]){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
    }return -1;
}


int main(){
    vector<int>vec={1,1,2,2,3,3,4,5,5,6,6,7,7,8,8,9,9};
    
    for(int i:vec){
        cout<<i<<" ";
    }cout<<endl;
    
    cout<<"the single element in this vector is "<<SingleElementInSortedArray(vec)<<endl;
    
}
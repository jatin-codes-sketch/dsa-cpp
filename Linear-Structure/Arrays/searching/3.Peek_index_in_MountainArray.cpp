#include<iostream>
#include<vector>
using namespace std;

int Peek_index_in_MountainArray(vector<int>&vec){
    int start=1,end=vec.size()-2;
    
    while(start<end){
        int mid=start+(end-start)/2;
        if(vec[mid - 1] < vec[mid] && vec[mid] > vec[mid + 1])return mid;
        if(vec[mid-1]<vec[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int>vec={3,4,5,6,7,1,0};
    
    cout<<"the array is ";
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }cout<<endl;
    
    cout<<"the peek index of the mountained array is "<<Peek_index_in_MountainArray(vec)<<endl;
    
    
    
    
    return 0;
}
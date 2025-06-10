#include<iostream>
#include<vector>
using namespace std;

bool search_in_2D_array(vector<vector<int>>mat,int target){
    int m=mat.size(),n=mat[0].size();
    int sR=0,eR=m-1;
    while(sR<=eR){
        int midR=sR+(eR-sR)/2;
        if(mat[midR][n-1]>=target && mat[midR][0]<target){
            int start=mat[midR][0],end=mat[midR][n-1];
            while(start<=end){
                int mid=start+(end-start)/2;
                if(mat[midR][mid]==target)return true;
                if(mat[midR][mid]>target)return end=mid-1;
                else start=mid+1;
            }
        }
        if(mat[midR][n-1]<target)sR=midR+1;
        else eR=midR-1;
    }
    return false;
}

int main(){
    
    vector<vector<int>>mat={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
    
    int target=2;
    
    if(search_in_2D_array(mat,target)){
        cout<<"the target is in matrix"<<endl;
    }else{
        cout<<"target is not in matrix"<<endl;
    }
    
    
    return 0;
}
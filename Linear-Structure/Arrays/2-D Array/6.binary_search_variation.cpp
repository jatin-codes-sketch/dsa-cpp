#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>&mat,int target){
    int m=mat.size(),n=mat[0].size();
    
    int r=0,c=n-1;
    while(r<n& c>=0){
        if(target==mat[r][c])return true;
        else if(target<mat[r][c]){
            c--;
        }else{
            r++;
        }
    }
    return false;
}

int main(){
    vector<vector<int>>mat={{1,2,3,4,5},{2,31,42,53,63},{313,423,523,623,723}};
    int target=43;
    
    if(searchMatrix(mat,target)){
        cout<<"this is in the matrix";
    }else {
        cout<<"this is not in matrix";
    }
    
    return 0;
}
#include<vector>
#include <iostream>
using namespace std;

bool isSafe(vector<vector<int>>&grid,int r,int c,int n,int expVal){
    if(r<0 || c<0 || r>=n || c>=n || grid[r][c]!=expVal)return false;
    
    if(expVal==n*n-1)return true;
    
    int a1=isSafe(grid,r-2,c+1,n,expVal);
    int a2=isSafe(grid,r-1,c+2,n,expVal);
    int a3=isSafe(grid,r+1,c+2,n,expVal);
    int a4=isSafe(grid,r+2,c+1,n,expVal);
    int a5=isSafe(grid,r-2,c-1,n,expVal);
    int a6=isSafe(grid,r-1,c-2,n,expVal);
    int a7=isSafe(grid,r+1,c-2,n,expVal);
    int a8=isSafe(grid,r+2,c-1,n,expVal);
    
    return a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8;
}

bool knightTour(vector<vector<int>>&grid){
    return isSafe(grid,0,0,grid.size(),0);
}

int main() {
    

    return 0;
}
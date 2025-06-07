#include<iostream>
#include<climits>
using namespace std;

int maxRowSum(int arr[][3],int r,int c){
    int maxSum=INT_MIN;
    for(int i=0;i<r;i++){
        int currentSum=0;
        for(int j=0;j<c;j++){
            currentSum+=arr[i][j];
        }
        maxSum=max(maxSum,currentSum);
    }
    return maxSum;
}

int maxColSum(int arr[][3],int r,int c){
    int maxSum=INT_MIN;
    for(int i=0;i<c;i++){
        int currentSum=0;
        for(int j=0;j<r;j++){
            currentSum+=arr[j][i];
        }
        maxSum=max(maxSum,currentSum);
    }
    return maxSum;
}


int main(){
    
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int rows=3,cols=3;
    
    int maxr=maxRowSum(arr,rows,cols);
    int maxc=maxColSum(arr,rows,cols);
    
    cout<<"maximum row sum: "<<maxr<<endl;
    cout<<"maximum col sum: "<<maxc;
    
    
    
    return 0;
}
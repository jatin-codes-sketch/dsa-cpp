#include<iostream>
using namespace std;

void merge_two_sorted_array(int A[],int B[],int m,int n){
    int idx=m+n-1,i=m-1,j=n-1;
    
    while(i>=0 && j>=0){
        if(A[i]>=B[j]){
            A[idx--]=A[i--];
        }else{
            A[idx--]=B[j--];
            
        }
    }
    
    while(j>=0){
        A[idx--]=B[j--];
    }
}



int main(){
    
    int A[]={4,7,9,10,0,0,0,0};
    int B[]={1,3,6,18};
    
    int n=sizeof(B)/sizeof(B[0]);
    int m=sizeof(A)/sizeof(A[0])-n;
    
    merge_two_sorted_array(A,B,m,n);
    
    cout<<"the merge of two array is ";
    for(int i=0;i<m+n;i++){
        cout<<A[i]<<" ";
    }cout<<endl;
    
    
    return 0;
}
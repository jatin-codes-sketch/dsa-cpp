#include <iostream>
using namespace std;

int findDuplicate(int arr[],int n){
    int slow=arr[0],fast=arr[0];
    
    do{
        slow=arr[slow];
        fast=arr[arr[fast]];
    }while(slow!=fast);
    
    slow=arr[0];
    while(slow!=fast){
        slow=arr[slow];
        fast=arr[fast];
    }
    
    return slow;
    
}


int main() {
    int arr[]={3,2,1,8,4,6,8,5,7,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    cout<<findDuplicate(arr,n)<<endl;
    
    
    return 0;
}
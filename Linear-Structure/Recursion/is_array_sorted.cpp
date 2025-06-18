#include <iostream>
#include<vector>
using namespace std;

bool isSort(vector<int>&arr,int n){
    
    if(n==0||n==1)return true;
    
    return arr[n-1]>=arr[n-2]&&isSort(arr,n-1);
}

int main() {
    vector<int>arr={2,3,4,5,7,6};
    int n=arr.size();
    
    if(isSort(arr,n)){
        cout<<"array is sort"<<endl;
    }else{
        cout<<"array is not sort"<<endl;
    }
    
    
    return 0;
}
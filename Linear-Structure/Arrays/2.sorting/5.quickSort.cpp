#include <iostream>
#include<vector>
using namespace std;

// Quick Sort Algorithm
// Time Complexity: O(n log n) on average, O(n^2) in the worst case
// Space Complexity: O(log n) due to recursive stack space
// Stable: No
// In-place: Yes
// Quick Sort is a divide-and-conquer algorithm that sorts an array by selecting a 'pivot' element and partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot.
// The sub-arrays are then sorted recursively.

int partition(vector<int>&arr,int st,int end){
    int idx=st-1,pivot=arr[end];
    
    for(int j=st;j<end;j++){
        if(arr[j]<=pivot){
            idx++;
            swap(arr[j],arr[idx]);
        }
    }
        idx++;
        swap(arr[idx],arr[end]);
        return idx;
}

void quickSort(vector<int>&arr,int st,int end){
    
    if(st<end){
        int pivotIdx=partition(arr,st,end);
        
        quickSort(arr,st,pivotIdx-1); // Sort left part
        quickSort(arr,pivotIdx+1,end); // Sort right part
    } 
    
}

int main() {
    
    vector<int>arr={2,4,2,1,7,5,8,1};
    
    quickSort(arr,0,arr.size()-1);
    
    for(int i:arr){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}
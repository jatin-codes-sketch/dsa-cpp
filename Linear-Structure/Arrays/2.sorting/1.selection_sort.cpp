#include<iostream>
#include<climits>
using namespace std;


void selection_sort(int arr[],int size){
    
    
    for(int i=0;i<size-1;i++){
         int minIndex=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[minIndex])minIndex=j;
        }        
        swap(arr[i],arr[minIndex]);
    }
}

int main(){
    int size;
    cout<<"enter the size of the array: "<<endl;
    cin>>size;
    
    int* arr=new int(size);
    
    for(int i=0;i<size;i++){
        cout<<"Enter the value of "<<i+1<<" of array: "<<endl;
        cin>>arr[i];
    }
    
    cout<<"the array is :";
    for(int i=0;i<size;i++)cout<<arr[i]<<" ";
    cout<<endl;
    
    selection_sort(arr,size);
    
    cout<<"the sorted array is :";
    for(int i=0;i<size;i++)cout<<arr[i]<<" ";
    cout<<endl;
    
    
    return 0;
}
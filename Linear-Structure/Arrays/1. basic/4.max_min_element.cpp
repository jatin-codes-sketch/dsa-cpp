#include<iostream>
#include<climits>
using namespace std;

int max_in_array(int arr[],int size){
    int max=INT_MIN;
    for(int i=0;i<size;i++){
        if(max<arr[i])max=arr[i];
    }
    
    return max;
}

int min_in_array(int arr[],int size){
    int min=INT_MAX;
    for(int i=0;i<size;i++){
        if(min>arr[i])min=arr[i];
    }
    return min;
}

int main(){
    int size;
    cout<<"enter the size of the array: "<<endl;
    cin>>size;
    
    int* arr=new int[size];
    for(int i=0;i<size;i++){
        cout<<"enter the value of "<<i+1<<" element in array: "<<endl;
        cin>>arr[i];
    }
    
    cout<<"the array is "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }cout<<endl;
    
    cout<<"the maximum value of the array is "<<max_in_array(arr,size);
    cout<<"the minimum value of the array is "<<min_in_array(arr,size);
    
    return 0;
}
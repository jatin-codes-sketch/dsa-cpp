#include<iostream>
using namespace std;

int capacity=5;

bool arrFull(int size){
    return capacity==size-1;
}

bool arrEmpty(int size){
    return size==0;
}

void insertAtBegin(int arr[],int val,int size){
    if(arrFull(size)){
        cout<<"array is already full cannot insert"<<endl;
        return;
    }
    
    if(arrEmpty(size)){
        arr[0]=val;
        size++;
        return;
    }
    
    for(int i=size-1;i>=0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=val;
    size++;
    
    
}

int main(){
    
    int arr[5]={1,3,5};
    int size=3;
    
    insertAtBegin(arr,12,size);
    
    for(int i:arr){
        cout<<i<<" ";
    }cout<<endl;
    
    
    return 0;
}
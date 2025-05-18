#include<iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

int main(){
    int size;
    cout<<"enter the size of array: "<<endl;
    cin>>size;

    int* arr=new int[size];

    for(int i=0;i<size;i++){
        cout<<"enter the "<<i+1<<" element of array: "<<endl;
        cin>>arr[i];
    }

    cout<<"the array is: "<<endl;
    printArray(arr,size);
    

}
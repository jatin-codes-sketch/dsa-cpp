#include<iostream>
using namespace std;

void reverse_array(int arr[],int size){
    int start=0;
    int end=size-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
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
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    reverse_array(arr,size);
    cout<<"the reversed array is: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete[] arr;
    // free the dynamically allocated memory
    // delete[] is used to free the dynamically allocated memory
    


    return 0;
}
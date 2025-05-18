#include<iostream>
using namespace std;

int sum_of_array(int arr[],int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){
int size;
cout<<"enter the size of the array: "<<endl;
cin>>size;

int* arr=new int[size];

for(int i=0;i<size;i++){
    cout<<"enter the "<<i+1<<" element of array: "<<endl;
    cin>>arr[i];
}

cout<<"the sum of the array is: "<<sum_of_array(arr,size)<<endl;
cout<<"the average of the array is: "<<(float)sum_of_array(arr,size)/size<<endl;
delete[] arr;
// free the dynamically allocated memory 

    return 0;
}
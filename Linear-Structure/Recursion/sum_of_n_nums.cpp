// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int sumofNnums(int n){
    if(n==1)return n;
    return n+sumofNnums(n-1);
}

int main() {
    int num;
    cout<<"enter the value of num: "<<endl;
    cin>>num;
    
    cout<<sumofNnums(num)<<endl;

    return 0;
}
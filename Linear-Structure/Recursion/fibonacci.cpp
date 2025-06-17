// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n==0||n==1)return n;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main() {
    int num;
    cout<<"enter the value of num: "<<endl;
    cin>>num;
    
    cout<<fibonacci(num)<<endl;

    return 0;
}
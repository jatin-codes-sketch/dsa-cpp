// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int factorial(int n){
    if(n==0)return 1;
    
    return n*factorial(n-1);
}

int main() {
    int num;
    cout<<"enter the value of num: "<<endl;
    cin>>num;
    
    cout<<factorial(num)<<endl;

    return 0;
}
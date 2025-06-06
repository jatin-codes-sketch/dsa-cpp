#include<iostream>
using namespace std;

string isPrime(int num){
    
    for(int i=2;i*i<=num;i++){
        if(num%i==0)return "non-prime";
    }
    return "Prime";    
}

int main(){
    
    int num;
    cout<<"enter the value of num: ";
    cin>>num;
    
    cout<<isPrime(num)<<endl;
    
    return 0;
}

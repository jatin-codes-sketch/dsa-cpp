#include<iostream>
#include<vector>
using namespace std;

int count_prime(int n){
    vector<bool>isPrime(n+1,true);
    int count=0;
    
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            count++;
        }
        for(int j=i*2;j<=n;j+=i){
            isPrime[j]=false;
        }
    }
    return count;
}



int main(){
    
    int n;
    cout<<"enter the range from where we count the prime numbers: ";
    cin>>n;
    
    cout<<count_prime(n);
    
    
    
    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;

bool isPrime(int n){
    if(n<=1)return false;
    if(n==2)return false;
    
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return false;
    }
    
    return true;
}


 bool checkPrimeFrequency(vector<int>&vec){
    
    unordered_map<int,int>m;
    
    for(int num:vec){
        m[num]++;
    }
    
    for(auto& [key,count]:m){
        if(isPrime(count))return true;
    }
    
    return false;
    
}


int main(){
    
    vector<int>vec={1,2,3,4,5};
    
    if(checkPrimeFrequency(vec)){
        cout<<"yes has prime frequency"<<endl;
    }else{
        cout<<" this hasn't prime frequency"<<endl;
    }
}
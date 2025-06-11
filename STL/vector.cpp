#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int>vec={1,2,3,4,5};
    // for printing the vector
    for(int val:vec){
        cout<<val<<" ";
    }cout<<endl;

    // vec.begin() is a iterator that gives us the address of the first index and vec.end() is also a iterator that give us the random addres not the last index of the vector
    cout<<*(vec.begin())<<endl;
    cout<<*(vec.end())<<endl;

    vector<int>::iterator it;
    for(it=vec.begin();it!=vec.end();it++){
        cout<<*(it)<<endl;
    }

    for(auto it=vec.rbegin();it!=vec.rend();it++){
        cout<<*(it)<<endl;
    }

    return 0;
}
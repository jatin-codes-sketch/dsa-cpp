#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int>l={1,2,3};
    l.push_back(4);
    l.emplace_back(5); 
    l.push_front(0);
    
    for(int val:l){
        cout<<val<<" ";
    }cout<<endl;

    l.pop_back();
    l.pop_front();

    for(int val:l){
        cout<<val<<" ";
    }cout<<endl;

    return 0;
}
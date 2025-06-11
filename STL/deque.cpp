#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int>d={1,2,3};
    d.push_back(4);
    d.emplace_back(5);
    d.emplace_front(0);
    d.push_front(-1);

    for(int val:d){
        cout<<val<<" ";
    }cout<<endl;

    d.pop_back();
    d.pop_front();

    for(int val:d){
        cout<<val<<" ";
    }cout<<endl;

    return 0;
}
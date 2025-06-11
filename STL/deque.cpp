#include<iostream>
#include<deque>  // double ended queue
using namespace std;

int main(){
    deque<int>d={1,2,3};
    d.push_back(4);
    d.emplace_back(5);   // for adding the element at back
    d.emplace_front(0);  // for adding the element at front 
    d.push_front(-1);

    for(int val:d){
        cout<<val<<" ";
    }cout<<endl;

    d.pop_back(); // for pop the element at back
    d.pop_front();  // for pop out the element at front

    for(int val:d){
        cout<<val<<" ";
    }cout<<endl;

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int main(){

    pair<int,int>p={1,2};

    cout<<p.first<<endl;
    cout<<p.second<<endl;

    pair<int,pair<char,int>>p1 {1,{'j',8}};

    cout<<p1.first<<endl;  // 1
    cout<<p1.second.first<<endl;   // j
    cout<<p1.second.second<<endl;  // 8

    vector<pair<int,int>>vec={{1,2},{3,4},{5,6}};

    // for push or add any value in this vec 
    vec.push_back({6,7}); // insert
    // or we can use emplace instead of giving the value in the form of pairs 
    vec.emplace_back(9,10);  // create in-place object creation 

    for(pair<int,int>p : vec){
        cout<<p.first<<" "<<p.second<<endl;
    }


    return 0;
}
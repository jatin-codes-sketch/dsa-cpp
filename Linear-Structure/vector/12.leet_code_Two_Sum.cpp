#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

pair<int,int> two_sum(vector<int>&v,int target){
    unordered_map<int,int>m;
    int n=v.size();

    for(int i=0;i<n;i++){
        int first=v[i];
        int second=target-first;
        if(m.find(second) !=m.end())return {i,m[second]};
        m[first]=i;
    }
    return {-1,-1};
}

int main(){

    vector<int>vec={2,7,11,15};
    int target=9;

    pair<int,int>p=two_sum(vec,target);

    cout<<p.first<<" "<<p.second<<endl;


    
    


    return 0;
}
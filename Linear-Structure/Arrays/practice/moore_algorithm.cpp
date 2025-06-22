#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>&vec){
    
    int ans=vec[0],freq=0;
    for(int i=0;i<vec.size();i++){
        if(freq==0)ans=vec[i];
        if(ans==vec[i])freq++;
        else freq--;
    }
    
    
    
    return ans;
    
}


int main(){
    
    vector<int>vec={3,1,5,3,5,3,3};
    
    cout<<majorityElement(vec);
    
    return 0;
}
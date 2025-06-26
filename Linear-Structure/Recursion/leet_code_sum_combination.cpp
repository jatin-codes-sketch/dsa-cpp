#include <iostream>
#include<set>
#include<vector>
using namespace std;

    set<vector<int>>s;

void helper(vector<int>&candidate,vector<vector<int>>&ans,vector<int>&combin,int target,int i){
    
    
    if(target<0 || i==candidate.size())return;
    
    if(target==0){
        if(s.find(combin)==s.end()){
            ans.push_back(combin);
            s.insert(combin);
        }
        return;
    }
    
    
    
    combin.push_back(candidate[i]);
    // single
    helper(candidate,ans,combin,target-candidate[i],i+1);
    helper(candidate,ans,combin,target-candidate[i],i); // mulitple
    combin.pop_back();
    
    // no change 
    helper(candidate,ans,combin,target,i+1);
    
    
}


vector<vector<int>> Combination(vector<int>&candidate,int target){
    vector<vector<int>>ans;
    vector<int>combin;
    
    helper(candidate,ans,combin,target,0);
    return ans;
}


int main() {
    
    cout<<"this is the code for leet code sum combination"<<endl;
    

    return 0;
}
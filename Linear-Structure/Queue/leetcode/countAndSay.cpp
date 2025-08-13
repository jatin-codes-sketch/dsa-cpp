#include<iostream>
#include<string>
#include<deque>
using namespace std;

void compression(string ans,string &update){
    if(ans.empty())return;
    
    deque<pair<char,int>>s;
    for(char c:ans){
        if(s.empty() || s.back().first !=c ){
            s.push_back({c,1});
        }else{
            auto last=s.back();
            s.pop_back();
            last.second++;
            s.push_back(last);
        }
    }
    
    while(!s.empty()){
        update+=to_string(s.front().second);
        update += s.front().first;
        s.pop_front();
    }
    
}

void helper(int n,string &ans,int val){
    if(val==n){
        return;
    }
    string update="";
    compression(ans,update);
    ans=update;
    
    helper(n,ans,val+1);
}

string countAndSay(int n){
    string ans="1";
    helper(n,ans,1);
    return ans;
}

int main(){
    int n=4;
    
    string ans=countAndSay(n);
    cout<<ans;
    return 0;
}
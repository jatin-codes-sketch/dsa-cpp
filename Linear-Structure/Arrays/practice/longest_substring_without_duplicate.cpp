#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

int longestSubstringWithoutDuplicate(string s){
    int left=0,right=0,n=s.length(),count=0;
    unordered_set<char>seen;
    
    while(right<n){
        if(seen.find(s[right])==seen.end()){
            seen.insert(s[right]);
            count=max(count,right-left+1);
            right++;
        }else{
            seen.erase(s[left]);
            left++;
        }
    }return count;
}


int main(){
    
    
    return 0;
}
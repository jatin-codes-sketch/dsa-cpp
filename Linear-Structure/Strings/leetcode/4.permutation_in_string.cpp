#include<iostream>
#include<string>
using namespace std;

bool sameFreq(int freq[],int windFreq[]){
    for(int i=0;i<26;i++){
        if(freq[i]!=windFreq[i])return false;
    }
    return true;
}

bool permutation_in_string(string s1,string s2){
    int freq[26]={0};
    for(int i=0;i<s1.length();i++){
        freq[s1[i]-'a']++;
    }
    
    int windowSize=s1.length();
    
    for(int i=0;i<s2.length();i++){
        int windIdx=0,idx=i;
        int windFreq[26]={0};
        
        while(idx<s2.length() && windIdx<windowSize){
            windFreq[s2[idx]-'a']++;
            idx++;windIdx++;
        }
        if(sameFreq(freq,windFreq)){
            return true;
        }
        
    }
    return false;
    
}



int main(){
    
    string s1="ab", s2="bsioaamnnd";
    
    if(permutation_in_string(s1,s2)){
        cout<<"s1 is available in s2 string"<<endl;
    }else{
        cout<<"not available"<<endl;
    }
    
    
    return 0;
}
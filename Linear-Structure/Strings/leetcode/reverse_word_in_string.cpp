#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

    string reverse_word_string(string s){
    int n=s.length();
    
    
    reverse(s.begin(),s.end());
    string str;
    for(int i=0;i<n;i++){
        string ans="";
        
        while(i<n && s[i]!=' '){
            ans+=s[i];
            i++;
        }
        
        reverse(ans.begin(),ans.end());
        if(ans.length()>0)str+=" "+ans;
        
    }
    return str.substr(1);
    
}


int main(){
    
    string word;
    cout<<"enter the string: ";
    // cin.ignore();
    getline(cin,word);
    
    cout<<"the reversed string is "<<reverse_word_string(word)<<endl;
    
    
    
    
    return 0;
}
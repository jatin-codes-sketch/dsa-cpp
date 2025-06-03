#include<iostream>
#include<cstring>
using namespace std;


bool isAlphaNumeric(char ch){
    if(ch>='0'&&ch<='9' ||
       tolower(ch)>='a'&&tolower(ch)<='z'){
           return true;
       }
       return false;
}


bool Palindrome(string str){
    
    int start=0,end=str.length()-1;
    
    while(start<end){
        if(!isAlphaNumeric(str[start])){
            start++;continue;
        }
        if(!isAlphaNumeric(str[end])){
            end--;continue;
        }
        
        if(str[start]!=str[end])return false;
        
        start++;end--;
    }
    
    return true;
    
}

int main(){
    
    string str;
    cout<<"enter the string: ";
    getline(cin,str);
    
    if(Palindrome(str)){
        cout<<"this is the palindrome"<<endl;
        return 0;
    }else{
        cout<<"this is not the palindrome"<<endl;
    }
    
    return 0;
}
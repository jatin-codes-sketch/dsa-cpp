#include<iostream>
#include<cstring>
using  namespace std;


string removeSequence(string str,string searchString){
    while(str.find(searchString)<str.length() && str.length()>0){
        
        
        str.erase(str.find(searchString),searchString.length());
    }
    return str;
}


int main(){
    
    string str;
    cout<<"enter the string"<<endl;
    cin>>str;
    
    string searchString;
    cout<<"enter the searching string: "<<endl;
    cin>>searchString;
    
    
    string str1=removeSequence(str,searchString);
    cout<<"the current string is "<<str<<" and after removal the search string the new string is "<<str1<<endl;
    
    
    
    
    
    return 0;
}
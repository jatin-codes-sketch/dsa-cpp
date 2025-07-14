#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool validParentheses(string str){
    stack<char>s;
    
    for(int i=0;i<str.length();i++){
        if(str[i]=='(' || str[i]=='{'|| str[i]=='['){
            s.push(str[i]);
        }else{
            if(s.empty())return false; 
            
            if((s.top()=='('&& str[i]==')')||
            (s.top()=='{'&& str[i]=='}')||
            (s.top()=='['&& str[i]==']')){
                s.pop();
            }else{
                return false;
            }
        }
    }
    return s.empty();
}

int main(){
     string input;
    cout << "Enter parentheses string: ";
    cin >> input;

    if(validParentheses(input)){
        cout << "Valid parentheses." << endl;
    } else {
        cout << "Invalid parentheses." << endl;
    }
    
    return 0;
}
#include<string>
#include<vector>
#include<iostream>
using namespace std; 

int compress(vector<char>&chars){
    int idx=0,n=chars.size();
    
    for(int i=0;i<n;){
        char ch=chars[i];
        int count=0;
        
        while(n>i && chars[i]==ch){
            count++;i++;
        }
        
        chars[idx++]=ch;
        
        if(count>1){
            string str=to_string(count);
            for(char dig:str){
                chars[idx++]=dig;
            }
        }
    }
    chars.resize(idx);
    return idx;
    
}

int main(){
    vector<char>chars={'a','a','a','a','b','c','c','d','d','d','e','f','f'};
    
    cout<<"the number of elements in vector will be "<<compress(chars)<<endl;
    
    cout<<"the vector is ";
    for(char i:chars){
        cout<<i<<" ";
    }cout<<endl;
    
    
    return 0;
}

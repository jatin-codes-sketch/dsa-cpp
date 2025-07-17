#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class minStack{
    public:
    stack<pair<int,int>>s;
    void push(int val){
        if(s.empty()){
            s.push({val,val});
        }else{
            int minVal=min(val,s.top().second);
            s.push({val,minVal});
        }
    }
    
    void pop(){
        s.pop();
    }
    
    void top(){
        s.top().first;
    }
    
    void getMin(){
        s.top().second;
    }
};

int main(){
    return 0;
}
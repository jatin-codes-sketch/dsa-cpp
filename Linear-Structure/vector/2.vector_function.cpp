#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    vector<int>vec;
    
    //push_back = pushing element in vector (at last)
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    
    cout<<"vector is:";
    for(int i:vec){
        cout<<i<<" ";
    }cout<<endl;
    
    //pop_back = remove last element of the vector
    vec.pop_back();
    vec.pop_back();
    
    cout<<"vector is: ";
    for(int i:vec){
        cout<<i<<" ";
    }cout<<endl;
    
    //front = get the first element of the vector 
    cout<<vec.front()<<endl;
    
    //back = get the last element of the vector 
    cout<<vec.back()<<endl;
    
    // at = get the value of the given index in the vector 
    cout<<vec.at(0)<<endl;
    
    
    
    return 0;
}
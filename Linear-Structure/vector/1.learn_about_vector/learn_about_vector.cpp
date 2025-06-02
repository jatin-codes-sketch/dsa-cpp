#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    // STL=Standard Template Library 
    // its parts are: 1. Container  2. Iterators    3. Algorithms   4.Functors
    
    // 1. Containers -> Vectors 
    vector<int>vec={1,2}; // [1,2] 
    vector<int>vec1(3,10); //[10,10,10]
    vec.size(); // size of vector vec is 2
    vec.push_back(3); // 1,2,3 
    vec.emplace_back(3); // 1,2,3 similar like push_back
    vec.pop_back(); // 1,2 delete or remove the last element of the vector 
    vec.at(1); // where 1 is the first index 
    vec.front(); // for first element 
    vec.back(); // for the last element of the vec
    
    vec.erase(vec.begin()+1); // it uses to erase the element in the vector(erase the first index value) 
    
    vec.insert(vec.begin()+2,100); // it uses to insert he value at the 2nd index of the vec with 100 and it will push the element at the left 
    

    return 0;
}
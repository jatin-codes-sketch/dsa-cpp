#include <iostream>
#include<vector>
using namespace std;

int removeDuplicate(vector<int>&vec){
    if(vec.empty())return 0;
    
    int i=0;
    for(int j=1;j<vec.size();j++){
        if(vec[j]!=vec[i]){
            i++;
            vec[i]=vec[j];
        }
        
    }
        return i+1;
}


int main() {
    
    vector<int>vec={1,1,1,2,2,3,3,4};
    
    int duplicate=removeDuplicate(vec);
    
    cout<<"the number of duplicate: "<<duplicate<<endl;
    
    for(int i:vec){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}
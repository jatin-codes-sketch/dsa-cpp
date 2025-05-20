#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    vector<int>vec;//Having no elements size=0
    cout<<vec.size()<<endl;//0
    
    vector<int>vec1={1,2,3,4,5,6};
    cout<<vec1.size()<<endl;//6 
    
    vector<int>vec3(5,1);
    cout<<vec3.size()<<endl;//size=5 and values will be 1
    for(int i:vec3){
        cout<<i<<endl;
    }
    
    return 0;
}
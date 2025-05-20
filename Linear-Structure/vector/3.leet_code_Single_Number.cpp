#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>&vec){
    int ans=0;
    for(int i:vec){
        ans^=i;
    }
    return ans;
}

int main(){
    vector<int>vec={1,3,4,6,1,6,4};
    cout<<singleNumber(vec);
    return 0;
}
// Time complexity = O(n)
// Space complexity = O(1)

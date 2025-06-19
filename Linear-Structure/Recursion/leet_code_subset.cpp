#include <iostream>
#include<vector>
using namespace std;

void allsubset(vector<int>&vec,vector<vector<int>>&subset,vector<int>&ans,int i){
    
    if(i==vec.size()){
        subset.push_back(ans);
        return;
    }
    
    ans.push_back(vec[i]);
    allsubset(vec,subset,ans,i+1);
    
    ans.pop_back();
    allsubset(vec,subset,ans,i+1);
    
    
    
}

int main() {
    vector<int>vec={1,2,3};
    vector<vector<int>>subset;
    int i=0;
    vector<int>ans;
    
    allsubset(vec,subset,ans,i);
    
    for (const auto& s : subset) {
        cout << "{ ";
        for (int val : s) {
            cout << val << " ";
        }
        cout << "}" << endl;
    }

    
    

    return 0;
}
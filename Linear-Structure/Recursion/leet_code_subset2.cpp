#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void allsubset(vector<int>&vec,vector<vector<int>>&subset,vector<int>&ans,int i){
    int n=vec.size();
    
    if(i==vec.size()){
        subset.push_back(ans);
        return;
    }
    
    ans.push_back(vec[i]);
    allsubset(vec,subset,ans,i+1);
    
    ans.pop_back();
    
    
    int idx=i+1;
    while(idx<n && vec[i]==vec[idx])idx++;
    allsubset(vec,subset,ans,idx);
    
    
    
    
}

int main() {
    vector<int>vec={1,2,2,1};
    vector<vector<int>>subset;
    int i=0;
    vector<int>ans;
    sort(vec.begin(),vec.end());
    
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
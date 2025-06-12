#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> missingAndDuplicate(vector<vector<int>>&grid){
    vector<int>ans;
    unordered_set<int>s;
    int n=grid.size();
    int a,b;

    int originalSum,sum;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum+=grid[i][j];
            if(s.find(grid[i][j])!=s.end()){
                a=grid[i][j];
                ans.push_back(grid[i][j]);
                break;
            }s.insert(grid[i][j]);
        }
    }
    originalSum=(n*n)*(n*n+1)/2;
    b=originalSum+a-sum;
    ans.push_back(b);

    return ans;
}

int main(){
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int trapping_water(vector<int>height){
    int n=height.size();
    vector<int>left(n,0);
    vector<int>right(n,0);
    
    left[0]=height[0];
    right[n-1]=height[n-1];
    
    for(int i=1;i<n;i++){
        left[i]=max(left[i-1],height[i]);
    }
    
    for(int i=n-2;i>=0;i--){
        right[i]=max(right[i+1],height[i]);
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=min(left[i],right[i])-height[i];
    }
    
    return ans;
    
}

int main() {
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped water: " << trapping_water(heights) << endl;
    return 0;
}

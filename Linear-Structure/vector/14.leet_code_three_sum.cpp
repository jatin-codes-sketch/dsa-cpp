#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;  
        int b = i + 1, c = n - 1;

        while (b < c) {
            int sum = nums[i] + nums[b] + nums[c];
            if (sum == 0) {
                ans.push_back({nums[i], nums[b], nums[c]});
                b++;
                c--;

                while (b < c && nums[b] == nums[b - 1]) b++;  
                while (b < c && nums[c] == nums[c + 1]) c--;  
            }
            else if (sum < 0) b++;
            else c--;
        }
    }
    return ans;
}

int main() {
    vector<int> num = {-2, 4, 1, -1, -3, 0, 1};
    vector<vector<int>> result = threeSum(num);

    for (auto triplet : result) {
        for (int x : triplet) cout << x << " ";
        cout << endl;
    }

    return 0;
}

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int maximumErasureValue(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> s;
    int left = 0, right = 0, sum = 0, maxVal = 0;

    while (right < n) {
        if (s.find(nums[right]) == s.end()) {
            s.insert(nums[right]);
            sum += nums[right];
            maxVal = max(sum, maxVal);
            right++;
        } else {
            s.erase(nums[left]);
            sum -= nums[left];
            left++;
        }
    }
    return maxVal;
}

int main() {
    vector<int> nums;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> val;
        nums.push_back(val);
    }

    int result = maximumErasureValue(nums);
    cout << "Maximum Erasure Value: " << result << endl;

    return 0;
}

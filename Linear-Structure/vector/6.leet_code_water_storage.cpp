
// Problem: Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines,
// which together with the x-axis forms a container, such that the container contains the most water.
// Note: You may not slant the container and n is at least 2.
// Example:
// Input: [2, 4, 1, 6, 4, 3, 6]
// Output: 18
// Explanation: The container formed by lines 1 and 4 (0-indexed) can hold 18 units of water.
// Approach: Use two pointers to find the maximum area. Start with the leftmost and rightmost lines, calculate the area,
// and move the pointer pointing to the shorter line towards the other pointer. Repeat until the two pointers meet.
// Time Complexity: O(n)
// Space Complexity: O(1)



#include <iostream>
#include <vector>
using namespace std;

int container_with_most_water(vector<int>& vec) {
    int left = 0, right = vec.size() - 1, ans = 0;
    
    while (left < right) {
        int width = right - left;
        int height = min(vec[left], vec[right]);
        int water = width * height;
        ans = max(ans, water);

        // Move the pointer pointing to the shorter line
        if (vec[left] < vec[right]) {
            left++;
        } else {
            right--;
        }
    }

    return ans;
}

int main() {
    vector<int> vec = {2, 4, 1, 6, 4, 3, 6};
    
    cout << "The maximum amount of water that can be stored: " 
         << container_with_most_water(vec) << endl;

    return 0;
}

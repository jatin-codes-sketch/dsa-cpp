#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> s;
    vector<int> left(n), right(n);
    
    // Left Nearest Smaller Element
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i])
            s.pop();
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Clear the stack for right calculation
    while (!s.empty())
        s.pop();

    // Right Nearest Smaller Element
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i])
            s.pop();
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Calculate maximum area
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        ans = max(ans, area);
    }

    return ans;
}


int main() {
    vector<int> histogram = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << largestRectangleArea(histogram) << endl;
    return 0;
}

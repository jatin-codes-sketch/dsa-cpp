#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pascalRow(int r) {
        vector<int> ans;
        long long result = 1;
        ans.push_back(1);

        for (int i = 1; i <= r; i++) {
            result = result * (r - i + 1) / i;
            ans.push_back(result);
        }

        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            ans.push_back(pascalRow(i));
        }

        return ans;
    }
};

int main() {
    int numRows;
    cin >> numRows;

    Solution sol;
    vector<vector<int>> triangle = sol.generate(numRows);

    for (const auto& row : triangle) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

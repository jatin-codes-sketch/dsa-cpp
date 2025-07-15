#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> next_greater_element(vector<int>& num) {
    stack<int> s;
    int n = num.size();
    vector<int> ans(n, 0);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && num[i] >= s.top()) {
            s.pop();
        }

        ans[i] = s.empty() ? -1 : s.top();
        s.push(num[i]);
    }

    return ans;
}

int main() {
    vector<int> nums;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    vector<int> result = next_greater_element(nums);

    cout << "Next Greater Elements:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

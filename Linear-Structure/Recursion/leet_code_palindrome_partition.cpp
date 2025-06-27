#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(string s) {
    string s1 = s;
    reverse(s1.begin(), s1.end());
    return s1 == s;
}

void helper(string s, vector<vector<string>>& ans, vector<string>& partitions) {
    if (s.size() == 0) {
        ans.push_back(partitions);
        return;
    }

    for (int i = 0; i < s.length(); i++) {
        string part = s.substr(0, i + 1);
        if (isPalindrome(part)) {
            partitions.push_back(part);
            helper(s.substr(i + 1), ans, partitions);  // FIXED LINE
            partitions.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> partitions;

    helper(s, ans, partitions);
    return ans;
}

int main() {
    string input = "aab";
    vector<vector<string>> result = partition(input);

    for (auto& partition : result) {
        for (auto& word : partition)
            cout << word << " ";
        cout << endl;
    }

    return 0;
}

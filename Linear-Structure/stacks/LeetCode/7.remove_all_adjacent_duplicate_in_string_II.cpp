#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string removeDuplicate(string str, int k) {
    stack<pair<char, int>> s; 
    
    for (char c : str) {
        if (!s.empty() && s.top().first == c) {
            s.top().second++;
        } else {
            s.push({c, 1});
        }
        
        if (s.top().second == k) {
            s.pop();
        }
    }
    
    string ans;
    while (!s.empty()) {
        ans.append(s.top().second, s.top().first);
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string str = "deeedbbcccdbaa";
    string ans = removeDuplicate(str, 3);
    cout << ans; 
    return 0;
}

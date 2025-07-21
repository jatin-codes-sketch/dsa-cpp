#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        if (s.empty()) return "";

        string s1 = "";
        int freq = 1;
        char currChar = s[0];
        s1 += s[0];

        for (int i = 1; i < s.length(); i++) {
            if (s[i] != currChar) {
                currChar = s[i];
                freq = 1;
                s1 += s[i];
            } else {
                if (freq < 2) {
                    s1 += s[i];
                    freq++;
                }
            }
        }

        return s1;
    }
};

int main() {
    Solution sol;
    
    // Sample test cases
    string input1 = "leeetcode";
    string input2 = "aaabaaaa";
    string input3 = "aabbaa";
    
    cout << "Input: " << input1 << " -> Output: " << sol.makeFancyString(input1) << endl;
    cout << "Input: " << input2 << " -> Output: " << sol.makeFancyString(input2) << endl;
    cout << "Input: " << input3 << " -> Output: " << sol.makeFancyString(input3) << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <algorithm> // <-- required for std::reverse
using namespace std;

int main() {
    string s = "hello";
    reverse(s.begin(), s.end()); // Reversing the string using STL function
    cout << "Reversed string: " << s << endl; // Output: "olleh"

    char str[] = "world";
    int n = sizeof(str) / sizeof(str[0]) - 1; // Length excluding null character
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]); // Manual reverse
    }
    cout << "Reversed C-style string: " << str << endl; // Output: "dlrow"

    return 0;
}


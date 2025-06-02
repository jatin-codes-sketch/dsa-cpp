#include<iostream>
#include<string>
using namespace std;

int main() {
    // C++ strings are objects that represent sequences of characters.
    // They are part of the C++ Standard Library and provide a convenient way to handle text.


    char str1[20] = "Hello"; // C-style string
    cout << "C-style string: " << str1 << endl;
    cout << "Length of C-style string: " << strlen(str1) << endl; // Output: 5

    char str2[20];
    cout<<"enter the value of string:"<<endl;
    cin.getline(str2, 20); // Reading a C-style string from user input getline(string,size, delimiter)

    string str = "Hello, World!"; // Initializing a string
    cout << "String: " << str << endl;

    // Accessing characters in a string
    cout << "First character: " << str[0] << endl; // Output: H
    cout << "Last character: " << str[str.length() - 1] << endl; // Output: !

    // String length
    cout << "Length of string: " << str.length() << endl; // Output: 13

    // Concatenation
    string str2 = " How are you?";
    string combined = str + str2;
    cout << "Combined string: " << combined << endl;

    // Substring
    string sub = str.substr(0, 5); // Extracts "Hello"
    cout << "Substring: " << sub << endl;

    return 0;
}
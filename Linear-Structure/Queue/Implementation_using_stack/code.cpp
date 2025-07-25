#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    stack<int> s1;
    stack<int> s2;

    // Push element to the back of the queue
    void push(int val) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(val);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Removes the element from front of queue
    void pop() {
        if (!s1.empty()) {
            s1.pop();
        } else {
            cout << "Queue is empty\n";
        }
    }

    // Get the front element
    int front() {
        if (!s1.empty()) {
            return s1.top();
        } else {
            cout << "Queue is empty\n";
            return -1;
        }
    }
}; // <-- missing semicolon fixed here

int main() {
    Solution q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl; // Should print 10
    q.pop();

    cout << "Front after pop: " << q.front() << endl; // Should print 20

    
    return 0;
}

#include "bits/stdc++.h"
using namespace std;

class Queue {
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int topVal = s2.top();
        s2.pop();
        return topVal;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int32_t main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.pop() << "\n";  // Should print 1
    q.push(5);
    cout << q.pop() << "\n";  // Should print 2
    cout << q.pop() << "\n";  // Should print 3
    cout << q.pop() << "\n";  // Should print 4
    cout << q.pop() << "\n";  // Should print 5

    return 0;
}



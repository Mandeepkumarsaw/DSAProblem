#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

class MinStack {
public:
    stack<pair<int, int>> s;

    MinStack() {
        // Constructor
    }

    void push(int val) {
        if (s.empty()) {
            s.push(make_pair(val, val));                   //Or s.push({val, val});
        } else {
            int minval = std::min(val, s.top().second);
            s.push({val, minval});                            
        }
    }

    void pop() {
        if (!s.empty()) {
            s.pop();
        }
    }

    int top() {
        if (!s.empty()) {
            return s.top().first;
        }
        throw runtime_error("Stack is empty");
    }

    int getMin() {
        if (!s.empty()) {
            return s.top().second;
        }
        throw runtime_error("Stack is empty");
    }
};

int main() {
    MinStack ms;

    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);

    cout << "Top element: " << ms.top() << endl;
    cout << "Minimum element: " << ms.getMin() << endl;

    ms.pop();
    cout << "After pop, top element: " << ms.top() << endl;
    cout << "After pop, minimum element: " << ms.getMin() << endl;

    return 0;
}
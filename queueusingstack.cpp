#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {            //O(n)
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {                //O(1)
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {              //O(1)
        return s1.top();
    }
    
    bool empty() {            //O(1)
        return s1.empty();
    }
};


int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl; // Should print 10
    cout << "Removed element: " << q.pop() << endl; // Should remove 10
    cout << "Front element after pop: " << q.peek() << endl; // Should print 20

    q.push(40);
    cout << "Removed element: " << q.pop() << endl; // Should remove 20
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}

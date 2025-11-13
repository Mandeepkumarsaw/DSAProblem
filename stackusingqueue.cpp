#include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {
        
    }
    
    void push(int x) {           //O(n)
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

       q1.push(x);
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {                //O(1)
        int ans = q1.front();   
        q1.pop();
        return ans;
    }
    
    int top() {                //O(1)
        return q1.front();
    }
    
    bool empty() {            //O(1)
        return q1.empty();
    }
};

int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << "\n";   // Should print 30
    cout << "Pop element: " << st.pop() << "\n";   // Should print 30
    cout << "Top after pop: " << st.top() << "\n"; // Should print 20

    st.pop(); // Removes 20
    st.pop(); // Removes 10

    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << "\n"; // Should print Yes

    return 0;
}
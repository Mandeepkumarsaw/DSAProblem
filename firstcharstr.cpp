#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        queue<int> Q;
        
        for(int i=0; i<s.size(); i++) {
              if(m.find(s[i]) == m.end()) {   //it means if it not find, then push it
              Q.push(i);
             }
           m[s[i]]++;

           while(Q.size()>0 && m[s[Q.front()]] > 1) {   //Q.front() stores index ie it acts like m[s[i]]
            Q.pop();   //if freq is > 1, pop that index and move on
           }
        }
        return Q.empty() ? -1 : Q.front();    //at lst only first Unique ele left at front of queue else -1;
    }
};

int main() {
    Solution sol;
    string str = "leetcode";  // Hardcoded test string

    int index = sol.firstUniqChar(str);
    if (index != -1) {
        cout << "First unique character: '" << str[index] << "' at index " << index << endl;
    } else {
        cout << "No unique character found." << endl;
    }

    return 0;
}

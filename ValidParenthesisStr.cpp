#include<bits/stdc++.h>
using namespace std;

class Solution {       //678
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for(char ch : s) {
            if(ch == '(') {
                low++;
                high++;
            }
            else if(ch == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;      // treat as ')'
                high++;     // treat as '('
            }

            if(high < 0) return false;  // too many ')'

            if(low < 0) low = 0;        // can't be negative
        }

        return low == 0;
    }
};

int main(){
    Solution obj;
    string S = "(*))";

    cout<<boolalpha<<obj.checkValidString(S);
    return 0;
}
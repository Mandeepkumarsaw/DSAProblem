#include<bits/stdc++.h>
using namespace std;

class Solution {  //796
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string doubled = s + s;    //abcdeabcde
        return doubled.find(goal) != string::npos;
    }
};

int main(){
    Solution obj;
    string s = "abcde";
    string goal = "cdeab";

    cout<<boolalpha<<obj.rotateString(s,goal);
    return 0;
}
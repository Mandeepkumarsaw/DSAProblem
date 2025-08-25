#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string temp = s;
        reverse(temp.begin(), temp.end());
        return  temp == s;
    }

    void getallParts(string s, vector<string>& partition,
                     vector<vector<string>>& ans) {
        // bc
        if (s.size() == 0) {
            ans.push_back(partition);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);

            if (isPalindrome(part)) {
                partition.push_back(part);
                getallParts(s.substr(i + 1), partition, ans);
                partition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;

        getallParts(s, partition, ans);
        return ans;
    }
};

int main(){
    Solution obj;
    string s = {"aab"};
    vector<vector<string>> res = obj.partition(s);

    cout<<"List of Palindrome: \n";
    for(const auto&  val : res){
        cout<<"{";
        for(const string& dig : val){
            cout<<"'"<<dig<<"',";
        }
        cout<<"},\n";
    }
  
    

    return 0;
}
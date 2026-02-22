#include <bits/stdc++.h>
#include <cmath>
using namespace std;



class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string letter[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res = {""};
        
        for(char ch : digits){    //dig=23
            vector<string> temp;
            string chars = letter[ch - '0'];   //abc
            for(string s:res){
                for(char c:chars){
                    temp.push_back(s+c);    //"a" "b" "c"
                }
            }
            res = temp;
        }
        return res;
    }
};

int main(){
    Solution obj;
    string digits = "23";
    vector<string> ans = obj.letterCombinations(digits);
     
    for(auto ele :  ans){
        cout<<ele<<" ";
    }cout<<endl;
    
    return 0;
}
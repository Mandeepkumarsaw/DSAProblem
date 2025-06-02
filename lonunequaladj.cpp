#include <bits/stdc++.h>    
using namespace std;

class lonunequaladj {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        if (words.empty() || groups.empty()) return result;
       
       result.push_back(words[0]);
        for(int i=1;i<groups.size();i++){
            if(groups[i] != groups[i-1]){
                result.push_back(words[i]);
               }
           
        }
        return result;
    }
};

int main(){
    vector<string> words = {"e","a","b"};
    vector<int> groups = {0,0,1};
    lonunequaladj obj;
    vector<string> res= obj.getLongestSubsequence(words,groups);
    

    cout<<"Subsequence: ";
    for(const string& s:res){
        cout<<s<<" ";
    }
    return 0;
}
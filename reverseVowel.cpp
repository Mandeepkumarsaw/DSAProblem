#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isVowel(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
           c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }

    string reverseVowels(string s) {
        int n=s.size();

        int left=0;
        int right=n-1;

        while(left<right){
         
           
            if(!isVowel(s[left])){ 
                left++;
                continue;
            }
            if(!isVowel(s[right])){
                right--;
                continue;
            }
            swap(s[left++],s[right--]);

        }
        return s;
        
    }
};


int main(){
    Solution sol;
    string s;cin>>s;
    cout<<sol.reverseVowels(s)<<endl;
    return 0;
}
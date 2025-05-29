#include <bits/stdc++.h>    
using namespace std;

class issequence {
public:
    bool isSubsequence(string s, string t) {
   int i=0,j=0;

   while(i<s.size() && j<t.size()){
    if(s[i]==t[j]){
        i++;
    }
    j++; 
   }

   return i == s.size();   //if (i == s.size()) {
                           //return true;
                           //} else {
                           //return false;  }

   }                     
};                      

int main(){
    string s="abc";
    string t="ahbgdc";
   issequence obj;
   bool res=obj.isSubsequence(s,t);
   
   cout << (res ? "Yes, it is a subsequence" : "No, it is not a subsequence") << endl;

}
  
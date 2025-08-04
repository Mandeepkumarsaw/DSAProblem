#include <bits/stdc++.h> 
using namespace std;

class validpalindrome {
public:
   bool isAlpha(char ch) {
    if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
            return true;
        }
        return false;
   }
   

    bool isPalindrome(string s) {
        int st = 0, end = s.length()-1;

        while(st < end) {
            if(!isAlpha(s[st])) { 
                st++ ; 
                continue;
            } if(!isAlpha(s[end])) {
                end--;
                continue;
            } if(tolower(s[st]) != tolower(s[end])) {
                return false;
            }

            st++;
            end--;
        }
        return true;
    }
};


int main(){
    string s = "A man, a plan, a canal: Panama";
    validpalindrome obj;
   
    // cout<<boolalpha<<obj.isPalindrome(s)<<" Palindrome"<<endl;

    cout<<(obj.isPalindrome(s) ? "TRUE" : "FALSE")<<" Palindrome " ;


    // for(char &val : s){         Optinal code to print that str in lower case(,&%$^)
    //     val = tolower(val);   
    //     cout<<val;
    // }
    // cout<<endl;

    return 0;
}
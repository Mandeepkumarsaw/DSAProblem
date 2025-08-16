#include<bits/stdc++.h>
using namespace std;

class palindromenum {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }

        long rev=0;
        int digit;
        int temp=x;

        while(x!=0){
            digit=x % 10;
            rev=rev * 10 + digit;
            x=x / 10;
            }
            if(rev == temp){
                return true;
            }
            else{
                return false;
            }
        
    }
};

int main(){
        palindromenum obj;
        int x= 353;

        if(obj.isPalindrome(x)) {
            cout<<"It's a Palindrome";
        } else {
            cout<<"Not a Palindrome";
        }
    
}

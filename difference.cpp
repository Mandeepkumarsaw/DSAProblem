#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class difference {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
    for (char c : s) result ^= c; // XOR all characters in s
    for (char c : t) result ^= c; // XOR all characters in t
    return result; // The extra character remains
   }
};

int main(){
    string s ="abcde";
    string t="abcd";
    difference obj;
    char res = obj.findTheDifference(s,t);
   cout<<"The difference btw s & t : "<<res<<endl;

}
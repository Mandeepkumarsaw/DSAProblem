#include <bits/stdc++.h>    
using namespace std;


class substringidx {
public:
    int strStr(string haystack, string needle) {
       return  haystack.find(needle);
    }
};

int main(){
    string haystack="sadbutsad";
    string needle="sad";
    
    substringidx obj;
    int res=obj.strStr(haystack,needle);

    cout<<res<<" ";

}
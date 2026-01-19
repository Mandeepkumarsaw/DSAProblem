#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string res =  "";

        for(int i=0;i<address.length();i++) {
            if(address[i]=='.'){
                res += "[.]";
            } else {
                res += address[i];
            }
        }

        return res;
    }
};

int main() {
    Solution obj;
    string address = "255.100.50.0";
    string print = obj.defangIPaddr(address);

    for(char C : print){
        cout<<C;
    }cout<<endl;

    return 0;
}
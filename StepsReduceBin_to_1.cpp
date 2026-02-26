#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        for(int i=s.size()-1;i>=1;i--){
            if((s[i]-'0') + carry == 1){       //carry always takes in odd 
                steps += 2;
                carry = 1;
            }else{
                steps += 1;
            }
        }
        return steps + carry;
    }
};


// Note:Suppose a odd num 13 so we have to +1 to make it 14 ie even ,then count steps :
// 13--->1101 
// 14--->1110

// If we add + 1,then we get 14 ie 1110 so let always a carry 1. 


//EX-2
    //             111
    //             + 1
    //            ------
    //             1000   ,here we take carry =1 bcoz on left side one bit increase


    int main(){
        Solution obj;
        string s = "1101";

        cout<<"Total Steps: "<<obj.numSteps(s);
        return 0;
    }
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int concatenatedBinary(int n) {
        int MOD  = 1e9 + 7;     //Prevent Overflow
        long long res = 0;
         
        for(int num=1;num<=n;num++){
            int digits = log2(num) + 1;    //gives the total size of n takes in binary to represent

            res = ((res << digits) % MOD + num) % MOD;   

            // res = (res << digits) + num;       //If you don't want to handle overflow cond
        }
        return res;
    }
};

int main(){
    Solution obj;
    int n = 2;
    cout<<obj.concatenatedBinary(n);
    
    return 0;
}



// For num = 1 to n:
// 1) Find binary length → digits = log2(num) + 1
// 2) Left shift previous result by digits (res *= 2^digits)
// 3) Add current number
// 4) Take modulo (1e9+7)

// Dry run for n = 2
// MOD = 1e9+7, res = 0

// num = 1:
// digits = 1    -->  size of decimal 1 in bin is also 1
// res = (0 << 1) + 1 = 1     --> adding space in res

// num = 2:
// digits = 2
// res = (1 << 2) + 2       ---> 1 << 2 == 100(internally its store in bin so it was actually decimal 4)
//     = 4 + 2
//     = 6

// Final result = 6
// Binary concatenation: "1" + "10" = "110"
// 110 (binary) = 6 (decimal)
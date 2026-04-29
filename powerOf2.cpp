#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool isPowerOfTwo(int n) {
    return (n > 0) && ( (n & (n - 1)) == 0 );
   }
};

int main(){
    Solution obj;
    int n=16;
    cout<<obj.isPowerOfTwo(n);

    return 0;
}
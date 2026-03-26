#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long ans = 0;

        while(a >= b){
            long long temp = b, multiple = 1;
            while(a >= (temp << 1)){
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            ans += multiple;
        }

        if((dividend < 0) ^ (divisor < 0)) ans = -ans;
        return (int)ans;
    }
};

int main() {
    Solution sol;
    vector<pair<int,int>> tests={{10,3},{7,-3},{INT_MIN,-1},{INT_MIN,1},{-15,2},{100,10}};
    for(auto &t:tests){
        cout<<"divide("<<t.first<<","<<t.second<<") = "<<sol.divide(t.first,t.second)<<endl;
    }
    return 0;
}

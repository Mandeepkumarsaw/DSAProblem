#include<bits/stdc++.h>
using namespace std;
 
//Method -1
// class staircount {
// public:
//    int climbStairs(int n) {
//     if (n <= 2) return n;

//     int prev1 = 1, prev2 = 2;
//     for (int i = 3; i <= n; i++) {
//         int current = prev1 + prev2;
//         prev1 = prev2;
//         prev2 = current;
//     }
//     return prev2;
// }

// };



//Method-2
class staircount {
    public:
    int climbStairs(int n) {
         if(n==1) return 1;

         int* dp = new int[n+1];
         dp[1]=1;
         dp[2]=2;

         for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+ dp[i-2];
         }
         return dp[n];
    }
};

int main(){
    int n=8;
    staircount obj;
    int res=obj.climbStairs(n);
    cout<<"The maximum ways to climb stairs: "<<res<<endl;
}
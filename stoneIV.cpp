#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;
    bool solve(int n){
        if(n==0) return false;

        if (dp[n] != -1){
            return dp[n] == 1 ? true : false;
        }

        for(int k=1;k*k <=n ;k++){
            if(solve(n-(k*k)) == false) 
                return dp[n] = true; 
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        dp.assign(n+1,-1);
        return solve(n);
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of stones: ";
    cin >> n;

    if(sol.winnerSquareGame(n))
        cout << "Alice wins the game!" << endl;
    else
        cout << "Bob wins the game!" << endl;

    return 0;
}

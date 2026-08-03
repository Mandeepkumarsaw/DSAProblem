#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[50005];

    int solve(vector<int>& stoneValue, int i) {
        if (i >= stoneValue.size())
            return 0;
        if (dp[i] != INT_MIN)
            return dp[i];

        int take = 0;
        int ans = INT_MIN;

        for (int k = 0; k < 3 && i + k < stoneValue.size(); k++) {
            take += stoneValue[i + k];
            ans = max(ans, take - solve(stoneValue, i + k + 1));
        }
        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        for (int i = 0; i < 50005; i++)
            dp[i] = INT_MIN;

        int diff = solve(stoneValue, 0);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};

int main() {
    Solution sol;

    vector<int> piles1 = {1, 2, 3, 7};
    cout << sol.stoneGameIII(piles1) << endl;  

    vector<int> piles2 = {1, 2, 3, -9};
    cout << sol.stoneGameIII(piles2) << endl;  

    vector<int> piles3 = {1, 2, 3, 6};
    cout << sol.stoneGameIII(piles3) << endl;  

    vector<int> piles4 = {1, 2, 3, -1, -2, -3, 7};
    cout << sol.stoneGameIII(piles4) << endl;  

    return 0;
}

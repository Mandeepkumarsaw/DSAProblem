#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& piles, int i, int j) {
        if (i > j) return 0;
        if (i == j) return piles[i];
        if (dp[i][j] != -1) return dp[i][j];

        int take_front = piles[i] + min(solve(piles, i+2, j), solve(piles, i+1, j-1));
        int take_back = piles[j] + min(solve(piles, i, j-2), solve(piles, i+1, j-1));

        return dp[i][j] = max(take_front, take_back);
    }

    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        int t_score = accumulate(piles.begin(), piles.end(), 0);
        int Alice_score = solve(piles, 0, piles.size()-1);
        int Bob_score = t_score - Alice_score;
        return Alice_score >= Bob_score;
    }
};

int main() {
    vector<int> piles = {3, 9, 1, 2};
    Solution sol;
    cout << (sol.stoneGame(piles) ? "Alice can win" : "Bob wins") << endl;
    return 0;
}

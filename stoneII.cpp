#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[2][101][101];
    int n;

    int solveWithAlice(vector<int>& piles,int person,int i,int M){
        if(i>=n) return 0;

        if(t[person][i][M] != -1){
            return t[person][i][M];
        }

        int result = (person==1) ? -1 : INT_MAX;
        int stone = 0;

        for(int x=1;x<= min(2*M,n-i);x++){
            stone += piles[i+x-1];

            if(person == 1){
                result = max(result,stone + solveWithAlice(piles,0,i+x,max(M,x)));
            } else{
                result = min(result,solveWithAlice(piles,1,i+x,max(M,x)));
            }
        }

        return t[person][i][M] = result;
    }

    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(t,-1,sizeof(t));
        return solveWithAlice(piles,1,0,1);
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> piles = {2,7,9,4,4};  // You can change values
    int result = sol.stoneGameII(piles);

    cout << "Maximum stones Alice can get: " << result << endl;

    return 0;
}

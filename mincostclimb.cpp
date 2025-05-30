#include <bits/stdc++.h>    
using namespace std;

class mincostclimb {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> minCost(n+1,0);     // Use vector for dynamic size


        for(int i=2;i<=n;i++){
            minCost[i]=
            min(
                (cost[i-1]+minCost[i-1]),
                (cost[i-2]+minCost[i-2])
                );

            }
            return minCost[n];
        }
};

int main(){
    vector<int> cost={10,15,20};
    mincostclimb obj;
    int res=obj.minCostClimbingStairs(cost);
    cout<<"The minimum cost of climbing stairs to TOP : "<<res<<endl;

    
}
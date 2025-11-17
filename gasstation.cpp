#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas = 0, totCost = 0;


        //unique sol already existed (check leetcode sol for easy redeabiity, this is just a more optimal version of leetcode)
        int start = 0, currGas = 0;
        for(int i=0; i<gas.size(); i++) {
            totGas += gas[i];
            totCost += cost[i];

            currGas += (gas[i] - cost[i]);

            if(currGas < 0) {
                start = i+1;
                currGas = 0;
            }
        }

        return totGas < totCost ? -1 : start;

        }
};        

int main() {
    Solution obj;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    int ans = obj.canCompleteCircuit(gas,cost);

    cout<<"The viable solution of this problem: "<<ans;
};
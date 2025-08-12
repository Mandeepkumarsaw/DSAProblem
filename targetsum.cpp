#include <bits/stdc++.h> 
using namespace std;

class targetsum {
public:
    int countWays(vector<int>& nums, int target, int i, int currentSum) {
        if (i == nums.size()) {
            return currentSum == target ? 1 : 0;
        }

        // Try adding the current number
        int add = countWays(nums, target, i + 1, currentSum + nums[i]);

        // Try subtracting the current number
        int subtract = countWays(nums, target, i + 1, currentSum - nums[i]);

        return add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countWays(nums, target, 0, 0);
    }
};

int main(){
    targetsum obj;
    vector<int> nums ={1,1,1,1,1};
    int target = 3;

    cout<<"Total Number of ways : "<<obj.findTargetSumWays(nums,target);
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
           sum += nums[i];
           nums[i] = sum;
        }
        return nums;
    }
};
int main() {
    Solution obj;
    vector<int> nums = {1,2,3,4};
    obj.runningSum(nums);

    cout<<"Running Sum: ";
    for(int ele : nums) {
        cout<<ele<<" ";
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for(int i=0;i<n;i++){
            res.push_back(nums[nums[i]]);
        }

        return res;
    }
};
int main() {
    Solution obj;
    vector<int> nums = {};
    obj.buildArray(nums);

    cout<<"After Operation: ";
    for(int ele : nums) {
        cout<<ele<<" ";
    }
    return 0;
}
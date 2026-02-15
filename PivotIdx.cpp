#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int n=nums.size();

        int totalSum = 0;
        for(int i=0; i<nums.size(); i++){
            totalSum += nums[i];
        }

       int leftSum = 0;
        for(int i=0;i<n;i++) {
            if(leftSum == totalSum - leftSum - nums[i]) return i;
            leftSum += nums[i];
        }


        return -1;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1,7,3,6,5,6};
    int res = obj.pivotIndex(nums);

    for(int ele : nums) {
        cout<<ele<<" ";
    }
    cout<<"--At idx ";
    cout<<res;
    cout<<"--> Ele: ";
    cout<<nums[res];
    cout<<" LHS == RHS";

    
    return 0;
}
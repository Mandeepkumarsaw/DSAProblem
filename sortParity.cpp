#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {         //Two pointer approach
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int st = 0;
        int end = nums.size()-1;

        while(st < end) {
            if(nums[st] % 2 == 1  && nums[end] % 2 == 0) {
                swap(nums[st],nums[end]);
            }

            if(nums[st] % 2 == 0) st++;
            if(nums[end] % 2 == 1) end--;
        }
        return nums;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {3,1,2,4};
    cout<<"After Filtering: ";
    obj.sortArrayByParity(nums);

    for(int num : nums){
        cout<<num<<" ";
    }

    return 0;
}
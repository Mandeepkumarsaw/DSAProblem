#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for(int i=0;i<n;i++){
            res = res ^ i;
            res = res ^ nums[i];
        }

        res = res ^ n;  //For last ele
        return res;
    }
};

int main(){
    Solution obj;
    vector<int> nums  = {0,2,3};

    cout<<"Missing num: ";
    cout<<obj.missingNumber(nums);
    
    return 0;
}
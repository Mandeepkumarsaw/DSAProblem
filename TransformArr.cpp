#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        for(int i=0;i<n;i++){
            if(nums[i] > 0) {
                int newIndex = (i + nums[i]) % n;
                res[i] = nums[newIndex];
            } else if (nums[i] < 0) {
                int newIndex = (i+nums[i]) % n;
                if(newIndex < 0) newIndex += n;    //fix -ve values
                res[i] = nums[newIndex];
            }  else {
                res[i] = 0;
            }
        }

        return res;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {3,-2,1,1};
    vector<int> arr = obj.constructTransformedArray(nums);
    for(int ch : arr){
        cout<<ch<<" ";
    }cout<<endl;

    return 0;
}
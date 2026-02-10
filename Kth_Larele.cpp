#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
      return nums[nums.size()-k];
    }
};

int main(){
    Solution obj;
    vector<int> arr = {3,2,1,5,6,6,4};
    int k = 2;       //2nd top ele is  6 (Duplicate allowed , if it's not allowed then o/p should be 5)
    
    cout<<obj.findKthLargest(arr,k);

    return 0;
}
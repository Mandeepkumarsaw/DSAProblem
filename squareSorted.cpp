#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++) {
            nums[i] = abs(nums[i]);
        }
        sort(begin(nums),end(nums));

        for(int i=0;i<n;i++){
            int square = nums[i] * nums[i];
            nums[i] = square;
        }

        return nums;
    }
};
int main(){
    Solution obj;
    vector<int> nums = {-4,-1,0,3,10};
    cout<<"Raw Array: ";
    for(int ele : nums){
        cout<<ele<<" ";
    }cout<<endl<<"After Squaring: ";

    obj.sortedSquares(nums);
    for(int ele : nums) {
        cout<<ele<<" ";
    }cout<<endl;

    return 0;
}
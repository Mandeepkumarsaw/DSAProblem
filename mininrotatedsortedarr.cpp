#include <bits/stdc++.h>    
using namespace std;

class mininrotatedsortedarr {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int right = nums.size() - 1;

        while(left<right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return nums[left];
    }
};

int main(){
    mininrotatedsortedarr obj;
    vector<int> nums = {4,5,6,71,2};

    cout<<obj.findMin(nums)<<endl;
}
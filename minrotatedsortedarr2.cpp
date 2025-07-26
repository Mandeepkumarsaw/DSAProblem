#include <bits/stdc++.h>    
using namespace std;

class minrotatedsortedarr2 {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;

        while(left < right){
            int mid = left +(right-left)/2;

            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else if(nums[mid] < nums[right]) {
                right = mid;
            }
            else {
                right--;
            }
        }
      return nums[left];
    }
};

int main(){
    minrotatedsortedarr2 obj;
    vector<int> nums = {2,2,2,0,1};

    cout<<obj.findMin(nums)<<endl;
    return 0;
}
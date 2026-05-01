#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n =nums.size();

        sort(nums.begin(),nums.end());
        int Closest = nums[0]+nums[1]+nums[2];   //or 100000

        for(int k=0;k<=n-3;k++){
            int l = k+1;
            int r=n-1;

            while(l<r){
                int sum = nums[l]+nums[r]+nums[k];

                if(abs(target - sum) < abs(target - Closest)){
                      Closest = sum;
                }

                if(sum < target) l++;
                else r--;
            }
        }
        return Closest;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {-1,2,1,-4};
    int target = 1;

    cout<<obj.threeSumClosest(nums,target);

    return 0;
}
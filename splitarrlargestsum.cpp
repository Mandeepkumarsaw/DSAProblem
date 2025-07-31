#include <bits/stdc++.h>    
using namespace std;

class splitarrlargestsum {
public:
    bool isValid(vector<int>& nums, int m, int mid) {             //O(n)
        int stu = 1;
        int pages = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mid) return false;

            if (pages + nums[i] <= mid) {
                pages += nums[i];
            } else {
                stu++;
                pages = nums[i];
            }
        }

        return stu <= m;
    }

    int splitArray(vector<int>& nums, int m) {             //O(logN*n)
        if (m > nums.size()) return -1;

        int sum = 0;
        for (int num : nums) sum += num;                      //O(n)

        int st = 0, end = sum;                               //Range
        int ans = -1;

        while (st <= end) {                                  //O(logN)
            int mid = st + (end - st) / 2;

            if (isValid(nums, m, mid)) {                      // moves towards left
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;                                // moves toward right
            }
        }
        return ans;
    }
};

int main(){
    splitarrlargestsum sl;
     vector<int> nums = {7,2,5,10,8};
     int m = 2;

    cout<<"Maximum sum of nums[] : "<<sl.splitArray(nums,m)<<" when divided "<<m<<" times."<<endl;
    return 0;
}
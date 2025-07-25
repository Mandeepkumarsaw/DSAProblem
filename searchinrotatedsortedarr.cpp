#include <bits/stdc++.h>    
using namespace std;

class searchinrotatedsortedarr {
public:
    int search(vector<int>& nums, int tar) {
        int st = 0, end=nums.size()-1;

        while(st <= end) {
            int mid = st + (end-st)/2;
             if(nums[mid] == tar){
                return mid;
            }
          
          if(nums[st] <= nums[mid]) {  //left
                if(nums[st] <= tar &&  tar <= nums[mid]){
                     end = mid -1;
                } else {
                    st = mid+1;
                }
            }

          else {  //right
                if(nums[mid] <= tar && tar <= nums[end]){
                  st = mid+1;
                } else { 
                    end = mid-1;
                }
            }
        }

        return -1;
    }
};

int main(){
    searchinrotatedsortedarr obj;
    vector<int> nums = {4,5,6,7,0,1,2};
    int tar = 0;

    cout<<"Target is located at index "<<tar<<" is:- "<<obj.search(nums,tar)<<endl;
}
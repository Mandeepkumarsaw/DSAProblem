#include <bits/stdc++.h>    
using namespace std;


class binarysearch {
public:
    int search(vector<int>& nums, int target) {
       int  st=0, end=nums.size()-1;
        while(st <= end){
            int mid = st + (end-st) / 2;

          if(target > nums[mid]){
            st = mid +1;
          }
          else if(target < nums[mid]){
            end = mid-1;
          }

          else {
            return mid;
          }
        }
        return -1;
        
    }
};

int main(){
    binarysearch obj;
    vector<int> nums = {2,5,7,9,14,19,23};
    int target = 14;

    int res=obj.search(nums,target);

    cout<<"The index value of target ele in array Nums is: "<<res<<endl;
}
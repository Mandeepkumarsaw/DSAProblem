#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
      int n=nums.size();
      if(n<4) return false;

      int i=0;

      //strictly inc
      while(i+1 < n && nums[i] < nums[i+1]) i++;
       if(i==0 || i==n-1) return false;

      //strictly dec
      while(i+1 < n && nums[i] > nums[i+1]) i++;
      if(i == n-1) return false;

      //strictly inc
      while(i+1 < n && nums[i] < nums[i+1]) i++;


      return i == n-1;   //if i reaches to n-1(last ele) we can return true bcoz we handle all exception in above code

        
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,3,5,4,2,6};
    cout<<boolalpha<<obj.isTrionic(nums);

    return 0;
}
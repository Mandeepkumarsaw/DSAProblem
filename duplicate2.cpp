#include <bits/stdc++.h>    
using namespace std;

class duplicate2 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
     unordered_map<int, int> seen;

     for (int i = 0; i < nums.size(); i++) {
         if (seen.count(nums[i]) && abs(i - seen[nums[i]]) <= k) {
            return true;
        }
        seen[nums[i]] = i; // Store the latest index of this number
    }
    
    return false;
   }
};

int main(){
    vector<int> nums = {0,1,2,3,4,5};
    vector<int> k = {3};
    duplicate2 obj;
    bool result=obj.containsNearbyDuplicate(nums,k[0]);

    cout<<result<<endl;
    return 0;
}
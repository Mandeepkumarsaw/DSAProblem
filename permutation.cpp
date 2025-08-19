#include<bits/stdc++.h>
using namespace std;

class permutation {
public:
    void getper(vector<int>& nums, int idx, vector<vector<int>> &ans) {
        if (idx == nums.size()) {
            ans.push_back({nums});
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);     //ith place => ith element choice
            getper(nums, idx + 1, ans);  

            swap(nums[idx], nums[i]);     //Backtracking
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getper(nums, 0, ans);
        return ans;
    }
};

int main(){
    permutation obj;
    vector<int> nums = {1,2,3};
   
    vector<vector<int>> result = obj.permute(nums);
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
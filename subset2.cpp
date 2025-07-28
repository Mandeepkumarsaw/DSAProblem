#include <bits/stdc++.h>    
using namespace std;



class subset2 {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i,
                       vector<vector<int>>& allSubsets) {
        if (i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }

        // include
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);

        ans.pop_back(); // backtracking

        int idx = i + 1; // logic remove duplicates in subsets
        while (idx < nums.size() && nums[idx] == nums[idx - 1])
            idx++;

        // exclude
        getAllSubsets(nums, ans, idx, allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> allSubsets;
        vector<int> ans;

        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};

int main() {
    subset2 sol;
    vector<int> nums = {1, 2, 2};  

    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "All subsets:\n";
    for (const auto& subset2 : result) {
        cout << "[";
        for (int num : subset2) {
            cout << num << "";
        }
        cout << "]\n";
    }

    return 0;
}
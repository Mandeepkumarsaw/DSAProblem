#include <bits/stdc++.h>    
using namespace std;

class Subset {
public:
    void getAllSubsets(vector<int>& nums, vector<int> &ans, int i,   //helper function
                       vector<vector<int>> &allSubsets) {

        if (i == nums.size()) {                 //base case
            allSubsets.push_back({ans});
            return;
        }

        // include
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);

        ans.pop_back();                   //backtracking

        // exclude
        getAllSubsets(nums, ans, i + 1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {                                //main func
        vector<vector<int>> allSubsets;                         //stores the final result
        vector<int> ans;                                                     //is the current subset being built.

        getAllSubsets(nums, ans, 0, allSubsets);          // Start Recursion


        return allSubsets;                                                  //After recursion completes, return all subsets
    }
};


int main() {
    Subset sol;
    vector<int> nums = {1, 2, 2};  

    vector<vector<int>> result = sol.subsets(nums);

    cout << "All subsets:\n";
    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << "";
        }
        cout << "]\n";
    }

    return 0;
}

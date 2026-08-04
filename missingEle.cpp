#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        unordered_set<int> s(nums.begin(), nums.end()); // fast lookup
        vector<int> res;

        for (int i = minVal; i <= maxVal; i++) {
            if (s.find(i) == s.end()) {
                res.push_back(i);
            }
        }

        return res;
    }
};


int main() {
    vector<int> nums = {3, 7, 2, 9, 5};
    Solution sol;
    vector<int> missing = sol.findMissingElements(nums);

    cout << "Missing elements: ";
    for (int x : missing) cout << x << " ";
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res; // store the max values
        deque<int> dq;   // Deque to keep track of indices of elements

        // 1st window
        for (int i = 0; i < k; i++) {
            while (dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // 2nd Window
        for (int i = k; i < nums.size(); i++) {
            res.push_back(nums[dq.front()]);

            // remove ele is not part of curr win
            while (dq.size() > 0 && dq.front() <= i - k) {
                dq.pop_front();
            }

            // remove the smaller vals
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]);

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};  // Hardcoded input
    int k = 3;

    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Max values in each sliding window of size " << k << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

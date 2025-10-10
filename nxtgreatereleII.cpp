#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> s;

        for(int i=(2*n)-1; i>0; i--) {
            while(s.size()>0 && nums[s.top()] <= nums[i%n]) {
                s.pop();
            }
            ans[i%n] = s.empty() ? -1 : nums[s.top()];
            s.push(i%n);
        }
        return ans;  //for valid idx we use modulo by the size which is n 
    }
};

int main() {
   Solution obj;
   vector<int> nums = {2,1,5,6,2,3};

   cout<<"Nxt Greater element(Cyclic)\n";
   vector<int> res = obj.nextGreaterElements(nums);
   for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
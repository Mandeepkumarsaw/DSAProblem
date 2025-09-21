#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>m;
        stack<int> s;

        for(int i=nums2.size()-1; i>=0; i--) {
            
            while(!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if(s.empty()) {
                m[nums2[i]] = -1;
            } else {
                m[nums2[i]] = s.top();
            }
            // m[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }

        vector<int> ans;
        for(int num : nums1) {
            ans.push_back(m[num]);
        }
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    cout<<"Nxt Greater element(right)\n";
    vector<int> result = obj.nextGreaterElement(nums1,nums2);

    for(int val:result) {
     cout<<val<<" ";
    } 
    cout<<endl;                             //-1 3 -1 
    

    return 0;
}
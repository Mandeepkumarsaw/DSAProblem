#include<bits/stdc++.h>
using namespace std;

class Solution {             //most ptimal approach
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0 , r=n-1;
        int lmax = 0, rmax = 0;
        int ans = 0;

        while(l < r) {
            lmax = max(lmax,height[l]);
            rmax = max(rmax,height[r]);

            if(lmax < rmax) {
               ans += lmax - height[l];
               l++;
            } else {
               ans += rmax - height[r];
               r--;
            }
        } 
        return ans;       
    }
};

int main() {
    Solution obj;
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};

    int ans = obj.trap(heights);
    cout<<"Maximum water holding capacity: "<<ans;

    return 0;
}
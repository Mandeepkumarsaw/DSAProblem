#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n,0); //right smaller nearest
        vector<int> left(n,0);  //left smaller nearest
        stack<int> s;

       
        //right smallest   
        for(int i=n-1; i>=0; i--) {
               while(s.size()>0 && heights[s.top()] >= heights[i]) {
                s.pop();
               }
               right[i] = s.empty() ? n : s.top();          //-1 is replaced by n 
               s.push(i);
        }


        //as we are working with same stack so before finding left smaller we have to clear(pop) stack so,
        while(!s.empty()) {
            s.pop();
        }



        //left smallest
        for(int i=0; i<n; i++) {
               while(s.size()>0 && heights[s.top()] >= heights[i]) {
                s.pop();
               }
               left[i] = s.empty() ? -1 : s.top();
               s.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            int width = right[i] - left[i] -1;
            int currArea = heights[i] * width;
            ans = max(ans,currArea); 
        }
        
        return ans;           
    }
};

int main() {
    Solution obj;
    vector<int> heights = {2,1,5,6,2,3};

    int res = obj.largestRectangleArea(heights);
    cout<<"Area of the largest rectangle in the histogram: "<<res;
 
    return 0;
}

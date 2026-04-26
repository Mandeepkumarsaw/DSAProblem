#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();

        int leftproduct = 1; 
        int rightproduct = 1;
        int result = nums[0];

        for(int i=0;i<n;i++){
              leftproduct = leftproduct == 0 ? 1 : leftproduct; 
              rightproduct = rightproduct == 0 ? 1 : rightproduct; 

              //preffix prod
              leftproduct *= nums[i];

              //suffix prod
              rightproduct *= nums[n-i-1];

              result  = max(result,max(leftproduct,rightproduct));

        }

        return result;
     
    }
};
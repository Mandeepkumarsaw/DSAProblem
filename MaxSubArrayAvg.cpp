#include<bits/stdc++.h>
using namespace std;

class Solution {  //643
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        double Tsum  = 0;
        for(int i=0;i<k;i++){
            Tsum += nums[i];
        }
        double TMax = Tsum;
        

        for(int j=k;j<n;j++){
            Tsum += nums[j];  //add new ele
            Tsum -= nums[j-k];  //Del first ele from window,they combine works as Sliding Window 

            TMax = max(Tsum,TMax);
        }

        double avg = TMax/k;
        return avg;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;

    cout<<obj.findMaxAverage(nums,k);

    return 0;
}
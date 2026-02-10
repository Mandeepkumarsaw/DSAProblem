#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;

        for (int ch:nums){
            s.insert(ch);
            if(s.size() > 3) {
                s.erase(s.begin());
            }
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};

int main() {
    vector<int> nums = {3,2,1};
    Solution obj;

    cout<<"Third Maximum Number in an array: ";
    cout<< obj.thirdMax(nums);

}
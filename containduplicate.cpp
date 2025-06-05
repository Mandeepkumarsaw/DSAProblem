#include <bits/stdc++.h>    
using namespace std;

class containduplicate {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        
       if(freq[num]>1) return true;
        }
      
        return false;
    }
};

int main(){
    vector<int> nums = {1,2,1,5};
    containduplicate obj;
    bool res=obj.containsDuplicate(nums);

    cout<<boolalpha<<res<<endl;
}


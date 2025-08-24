#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   set<vector<int>> s;    //For unique ele and in order 
   

   void helper(vector<int>& arr, int target,int i ,vector<int> &combin,vector<vector<int>> &ans) {
    int n =arr.size();

    if(i >= n || target < 0) return;

    if(target == 0){
        if(s.find(combin)  == s.end()) {   //Returns true if combin is NOT present in the set s either false;


              ans.push_back(combin);
              s.insert(combin);
        }
      
        return;
    }

    
   combin.push_back(arr[i]);

   helper(arr,target-arr[i],i+1,combin,ans);       //include single times
   helper(arr,target-arr[i],i,combin,ans);            //include multiple times

   combin.pop_back();     //Backtrack
   helper(arr,target,i+1,combin,ans);   //exclusion

   }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> combin;
        vector<vector<int>> ans;

        helper(arr,target,0,combin,ans);
         return ans;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {2,3,6,7};
    int target = 7;

    vector<vector<int>> res = obj.combinationSum(arr,target);

    cout<<"The combine Sum: ";
    for(auto& val : res){
        cout<<"{";
        for(int dig : val){
            cout<<dig<<",";
        }
        cout<<"} , "<<endl;
    }

    return 0;
}
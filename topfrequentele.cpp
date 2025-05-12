#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;





class topfrequentele {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int,int> freq;

     for(int num : nums){
        freq[num]++;
     }

     priority_queue<pair<int,int>> pq;
     for(auto& pair:freq){
        pq.push({pair.second,pair.first});
     }

     vector<int> result;
     while(k>0 && !pq.empty()){
        result.push_back(pq.top().second);
        pq.pop();
        k--;
     }
     return result;
    }
};



int main() {
    topfrequentele sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};  // Example input
    int k = 2;

    vector<int> result = sol.topKFrequent(nums,k);
     cout<<"Top "<<k <<"frequent element: ";
     for(int num:result){
        cout<<num<<" ";
     }
     cout<<endl;

     return 0;
    }
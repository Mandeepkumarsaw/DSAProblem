#include <bits/stdc++.h> 
using namespace std;

class sortcolors {
public:
    //   void sortColors(vector<int>& nums) {  //Overall O(n)-- not optimal
    //    int n = nums.size();
    //    int count0 =0 , count1=0, count2=0;
  
    //    for(int i=0; i<n; i++){        //O(n)
    //       if(nums[i]==0) count0++;
    //       else if(nums[i] == 1) count1++;
    //       else count2++;
    //    }
  
    //    int idx=0;
    //    for(int i=0;i<count0;i++){    //O(n)
    //       nums[idx++] = 0;
    //    } for(int i=0;i<count1;i++){
    //       nums[idx++] = 1;
    //    } for(int i=0;i<count2;i++){
    //       nums[idx++] = 2;
    //    }
  
    //   } 

    // Dutch National Flag Algo
       void sort(vector<int>& nums) {           //best case--optimal approach
       int n = nums.size();
       int low = 0 , mid = 0, high = n-1;
       
       while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[mid],nums[low]);
            mid++,low++;
        } else if(nums[mid]== 1) {
             mid++;
        } else {
            swap(nums[mid],nums[high]);
            high--;
        }
       }
    }

    void printArray(vector<int> nums){
        cout<<"The new sorted array : ";
        for(int val : nums){ 
            cout<<val;
        }
        cout<<endl;
    }
};

int main(){
    sortcolors obj;
    vector<int> nums = {1,2,1,2,1,1,0,1,0,2,1,0,0,0,2,1,2,2,0,1,2};
  
    // obj.sortColors(nums);
    obj.sort(nums);            //O(n)--optimal approach
    obj.printArray(nums);
    return 0;
}
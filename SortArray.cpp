#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




class Solution {
    void merge(vector<int> & nums,int st,int end){

     if(st < end){
       int mid = st +(end-st)/2;

       //left half
       merge(nums,st,mid);
       //right half
       merge(nums,mid+1,end);

        mergeSort(nums,st,mid,end);
        }
    }
     
     void mergeSort(vector<int>& nums,int st,int mid,int end) {
        vector<int> temp;
        int i = st;   //start pointer for left array
        int j = mid+1;  //start pointer for right array

        while(i<=mid && j<=end){
            if(nums[i] > nums[j]){
                temp.push_back(nums[j++]);
            } else {
                temp.push_back(nums[i++]);
            }
        }

        //LeftOver ele for LEFT subarray
        while(i<=mid){
            temp.push_back(nums[i++]);
        }

        //leftOver ele for RIGHT subarray
        while(j<=end){
            temp.push_back(nums[j++]);
        }

         //copy ele of temp to Original nums at original Postion
        for(int idx=0; idx<temp.size(); idx++){
        nums[idx+st]=temp[idx];         //[+st] --> VVI for putting ele at their destination idx
         }
    }

    
public:
//main func
    vector<int> sortArray(vector<int>& nums) {
        merge(nums,0,nums.size()-1);

        return nums;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {8,5,1,6,4,7};

    cout<<"Sorted Array: ";
    obj.sortArray(nums);
    for(int num : nums) {
        cout<<num<<" ";
    }

    return 0;
}
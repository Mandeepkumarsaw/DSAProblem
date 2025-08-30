#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
     int n = arr.size();
     int maxlength = 0;
     int i=1;

     while(i < n-1) 
     {
        //check for peak
        if(arr[i-1] < arr[i] && arr[i] > arr[i+1]) 
        {
               int left = i-1;
               int right = i+1;
     
               while(left > 0 && arr[left] > arr[left-1]) {
                 left--;
               }
     
               while(right < n-1 && arr[right] > arr[right+1]){
                 right++;
               }
     
               maxlength = max(maxlength,right-left + 1);

               i = right;

        } else {
               
              i++;
        }
     
     }

     return maxlength;
     
    }
};

int main(){
    Solution obj;
    vector<int> arr = {2, 1, 4, 7, 3, 2};

    int res=obj.longestMountain(arr);
    cout<<"Longest Mountain is of Length : "<<res;

    return 0;
}


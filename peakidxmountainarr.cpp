#include <bits/stdc++.h>    
using namespace std;

class peakidxmountainarr {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st=1 , end =arr.size()-2;   //starts from 1 and n-2 bcoz of more optimization
        

      while(st <= end){
        int mid = st + (end - st) / 2;

        if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
            return mid;
        } else if(arr[mid -1] < arr[mid]){   //check on right side of mid
             st = mid + 1;
        } else {  //left side of mid
            end = mid - 1;
        }

      }
    return -1;

    }
};

int main(){
    peakidxmountainarr obj;
    vector<int> arr = {0,2,5,6,9,8,4,1};
    int res = obj.peakIndexInMountainArray(arr);

    cout<<res<<endl;  //return idx=4 ie 9 in arr
}
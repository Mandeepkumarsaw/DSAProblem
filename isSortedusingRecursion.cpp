#include <bits/stdc++.h>    
using namespace std;
  
//check if array is sorted
bool isSorted(vector<int> arr, int n) {  //n is size of array
    if(n==0 || n==1) {
        return true;
    }

   return arr[n-1] >= arr[n-2] && isSorted(arr, n-1);
}

int main(){
    vector<int> arr ={1,2,3,8,5};
    int n =arr.size();
    cout<<boolalpha<<isSorted(arr,n)<<endl;  //boolalpha is used for "true" and "false "
    return 0;
}
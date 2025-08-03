#include <bits/stdc++.h> 
using namespace std;

class merge2arr {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, idx = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[idx--] = nums1[i--];
            } else {
                nums1[idx--] = nums2[j--];
            }
        }
        while (j >= 0) {
            nums1[idx--] = nums2[j--];
        }
    }
    

     void printArray(vector<int>& nums1) {
        cout<<"The new sorted arr : ";
        for(int val : nums1){
            cout<<val<<" ";
        }
        cout<<endl;
       }
    
};

int main(){
    vector<int> nums1 = {4,5,6,0,0,0};
    vector<int> nums2 = {1,2,3};
    int m=3;
    int n =3;


    merge2arr obj;
    obj.merge(nums1,m,nums2,n);
    obj.printArray(nums1);
    
    return 0;
}
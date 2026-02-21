#include <bits/stdc++.h> 
using namespace std;


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

//Pattern - A
class Solution {
    int isBadVersion(int x){
        return x;
    }
public:
    int firstBadVersion(int n) {
        int l=1;
        int r = n;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(isBadVersion(mid)){
                r = mid-1;
            } else {
                l = mid+1;
            }
        } 
        return l;
    }
};

//PATTERN - B
while(l < r){
    int mid = l + (r-l)/2;
    if(isBadVersion(mid)){
        r = mid;       // keep mid, could be the first bad
    } else {
        l = mid+1;     // skip mid, must be later
    }
}
return l;
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class sqrtn {
public:
    int mySqrt(int x) {
        return static_cast<int>(sqrt(x)); 
        
    }

        //Binary Search
        int mySqrt(int x) {
            int low = 1;
            int high = x;
            while(low <= high){
                  long long mid = low + (high - low)/2;
                  long long val = mid * mid;
                  if(val > x){
                    high = mid-1;
                  }else{
                    low = mid+1;
                  }
            }
            return high;
        }
};





int main(){
    int x=10;
    sqrtn obj;

    cout<<"The square of "<<x<<" : "<<obj.mySqrt(x)<<endl;
}
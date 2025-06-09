#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class sqrtn {
public:
    int mySqrt(int x) {
        return static_cast<int>(sqrt(x)); 
        
    }
};

int main(){
    int x=10;
    sqrtn obj;

    cout<<"The square of "<<x<<" : "<<obj.mySqrt(x)<<endl;
}
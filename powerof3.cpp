#include <bits/stdc++.h> 
using namespace std;

class powerof3 {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;

        while(n%3==0) {
            n /= 3;
        }
        return n==1;
       }
};

int main(){
    powerof3 obj;
    int n =27;
    cout<<n<<" is power of 3 is- ";
    cout<<boolalpha<<obj.isPowerOfThree(n);
}

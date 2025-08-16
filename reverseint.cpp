#include<bits/stdc++.h>
using namespace std;

class reverseint {
public:
    int reverse(int n) {
       int reversenum = 0;
          while(n !=0 ) {
             int dig = n%10;
             if(reversenum > INT_MAX/10 || reversenum < INT_MIN/10){
                return 0;
             }
             reversenum = reversenum*10 + dig;
             n /= 10;
           }

    return reversenum;
     }
};     

int main() {
    reverseint obj;
    cout<<obj.reverse(7523);
}




#include <bits/stdc++.h>    
using namespace std;

class Fibonum {
public:
    int fib(int n) {
  if(n==0) return 0;
  if(n==1) return 1;

   int prev1=0 , prev2=1;
   for(int i=2;i<=n;i++){
        int curr = prev1 + prev2;
         prev1=prev2;
         prev2=curr;
         }
     
      return prev2;  
        
    }
};

int main(){
    int n=5;
    Fibonum obj;
    int res=obj.fib(n);

    cout<<"Fibonacci of "<<n<<" is -> "<<res<<endl;
}
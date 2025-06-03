#include <bits/stdc++.h>    
using namespace std;

class Tribonaccinum {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;

        int a=0,b=1,c=1,result;
        for(int i=3;i<=n;++i){
            result=a+b+c;
            a=b;
            b=c;
            c=result;
        }
        return result;
        
    }
};

int main(){
    int n=5;
    Tribonaccinum obj;
    int sol=obj.tribonacci(n);

    cout<<"Triibonacci Number: "<<sol<<endl;
}
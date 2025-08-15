#include<bits/stdc++.h>
using namespace std;


class countprime {
public:
    int primeRange(int n) {
        if(n<=2) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] =
            false; // make sure to make  0 and 1 num be false;

        for (int i = 2; i * i < n;i++) {           // cond to check single digit is prime or not
            if (isPrime[i]) { //if true
                for (int j = i * i; j < n;
                     j += i) { // logic to check from 2 to n(range)
                    isPrime[j] = false;
                }
            }
        }
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i])  //if true
                ans++;
        }
        return ans;
    }

    int countPrimes(int n) { 
        return primeRange(n); 
        }
};

int main(){
    int n = 45;
    countprime obj;

    cout<<"Total number of Prime number from 2 to "<<n<<" is :"<<obj.primeRange(n);
    return 0;
}
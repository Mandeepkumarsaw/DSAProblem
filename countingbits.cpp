#include <bits/stdc++.h>
using namespace std;

class countingbits {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0;i<=n;i++){
           ans[i]=ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};

int main(){
    int n= 2;
    countingbits obj;
    vector<int> ans=obj.countBits(n);
   
    int res=0;
    //for printing
    for(int i=0;i<=n;i++){
    res += ans[i];
    cout<<ans[i]<<" ";
        }

    cout<<"\nSum of set bits: "<<res<<endl;
     

    return 0;
}
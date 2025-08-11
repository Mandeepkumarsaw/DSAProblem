#include <bits/stdc++.h> 
using namespace std;


class rangequeryofpow {
public:
     void printArray(vector<int> ans){
        cout<<"Final Array build : ";
        for(const& val : ans){
           cout<<"'"<<val<<"'";
      }
      cout<<endl;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1'000'000'007;
        vector<int> powers;
        // Build the "powers" array
        while (n > 0) {
            int x = n & -n; //to calculate 2 powers of x((2^x)
            powers.push_back(x);
            n -= x;
        }

        vector<int> ans;
        // Process each query with modulo
        for (const auto& q : queries) {
            long long prod = 1;
            for (int i = q[0]; i <= q[1]; ++i) {
                prod = prod * powers[i] % MOD;
            }
            ans.push_back((int)prod);
        }
        return ans;





    }

   
};

int main(){
    rangequeryofpow obj;
    int n = 15 ;
    vector<vector<int>> queries = {{0,1},{2,2},{0,3}};
    
    vector<int> output=obj.productQueries(n,queries);
    obj.printArray(output);

    return 0;
}
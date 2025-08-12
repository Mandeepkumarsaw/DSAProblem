#include <bits/stdc++.h> 
using namespace std;


//method 1
class rangequeryofpow {
public:
    int M=1e9+7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powers;
        vector<int>result;

        //Build power arr
        for(int i=0;i<32;i++){
            if((n & (1 << i)) != 0) {  //check that ith bit is in set or not if true then it store
            powers.push_back(1<<i);  //2 ka power i(2^i)

            }
        }

        for(auto &q : queries){
            int st=q[0];;
            int end=q[1];

            long long product = 1;
            for(int i=st ; i<=end ; i++) {
                product = (product * powers[i]) % M;
            }
            result.push_back(product);
        }
        return result;
    }

    void printArray(vector<int> ans){
        cout<<"Final Array build : ";
        for(const& val : ans){
           cout<<"'"<<val<<"'";
      }
      cout<<endl;
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



//Method 2


// class rangequeryofpow {
// public:
//      void printArray(vector<int> ans){
//         cout<<"Final Array build : ";
//         for(const& val : ans){
//            cout<<"'"<<val<<"'";
//       }
//       cout<<endl;
//     }

//     vector<int> productQueries(int n, vector<vector<int>>& queries) {
//         const int MOD = 1'000'000'007;
//         vector<int> powers;
//         // Build the "powers" array
//         while (n > 0) {
//             int x = n & -n; //This checks whether the n-th bit is set
//             powers.push_back(x);
//             n -= x;
//         }

//         vector<int> ans;
//         // Process each query with modulo
//         for (const auto& q : queries) {
//             long long prod = 1;
//             for (int i = q[0]; i <= q[1]; ++i) {
//                 prod = prod * powers[i] % MOD;   //check prod to be in limit of int(>2^31)
//             }
//             ans.push_back((int)prod);

//         }
//         return ans;
//     }

// };

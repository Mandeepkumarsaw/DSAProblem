#include <bits/stdc++.h>
using namespace std;

class Solution {  //Brute Force Approach
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        map<int, vector<int>> mp;

        vector<int> res;

        //fill map using[i+j]
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);   //i+j --> UPWARD direction
                                                //i-j --> DOWNWARD direction
            }
        }

        bool flip = true;
        for(auto &it : mp){
            if(flip) {
                //it.second ko reverse krdo
                reverse(it.second.begin(),it.second.end());
            }

            for(int &num : it.second) {
                res.push_back(num);
            }

            flip = !flip;
        }
        return res;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> mat = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<int> ans = obj.findDiagonalOrder(mat);
    for(auto &ele : ans){
        cout<<ele<<" ";
    }

    return 0;
}













//Optimed version
// class Solution {
// public:
//     vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
//         int m = mat.size();
//         int n = mat[0].size();

//         vector<vector<int>> diag(m + n - 1);

//         // Step 1: Fill diagonals using i+j
//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 diag[i + j].push_back(mat[i][j]);
//             }
//         }

//         // Step 2: Traverse and build result
//         vector<int> res;

//         for(int d = 0; d < diag.size(); d++) {
//             if(d % 2 == 0) {
//                 // even diagonal → reverse
//                 reverse(diag[d].begin(), diag[d].end());
//             }

//             for(int val : diag[d]) {
//                 res.push_back(val);
//             }
//         }

//         return res;
//     }
// };
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m = mat.size();  //row wise traversal only
        int Dsum = 0;

        for(int i=0;i<m;i++){
            Dsum += mat[i][i];
            Dsum += mat[i][m-1-i];
        }

        if(m%2 == 1) Dsum -= mat[m/2][m/2];  // remove double-counted center

        return Dsum;
    }
};
int main(){
    Solution obj;
    vector<vector<int>> mat = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout<<"Diagonal Sum of this matrix: "<<obj.diagonalSum(mat);
    return 0;

}
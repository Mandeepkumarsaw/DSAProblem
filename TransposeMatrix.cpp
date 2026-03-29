#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n =matrix[0].size();
        vector<vector<int>> res(n,vector<int>(m));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};

int main() {
    Solution obj;
            vector<vector<int>> matrix = {
                  {2,4,-1},
                  {-10,5,11},
                  {18,-7,6}
            };

        vector<vector<int>> transpose =  obj.transpose(matrix);
        int m = transpose.size();
        int n = transpose[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<transpose[i][j]<<" ";
            }cout<<endl;
        }


        return 0;     

}
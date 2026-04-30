#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> res(n,vector<int>(n));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res[j][n-1-i]=matrix[i][j];
            }
        }
        matrix=res; 
    }
};

int main(){
    Solution obj;
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    obj.rotate(matrix);

    for(auto &ele : matrix){
        for(auto &x:ele){
            cout<<x<<" ";
        } cout<<endl;
    }

   return 0;

}
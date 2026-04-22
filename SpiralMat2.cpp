#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int srow=0, erow=n-1;
        int scol=0, ecol=n-1;
        int num=1;

        while(srow<=erow && scol<=ecol){
            for(int i=scol;i<=ecol;i++) matrix[srow][i]=num++;
            for(int i=srow+1;i<=erow;i++) matrix[i][ecol]=num++;
            if(srow<erow){
                for(int i=ecol-1;i>=scol;i--) matrix[erow][i]=num++;
            }
            if(scol<ecol){
                for(int i=erow-1;i>=srow+1;i--) matrix[i][scol]=num++;
            }
            srow++; erow--;
            scol++; ecol--;
        }
        return matrix;
    }
};

int main(){
    Solution sol;
    int n;cin>>n;
    vector<vector<int>> res=sol.generateMatrix(n);
    for(auto &row:res){
        for(auto &val:row) cout<<val<<" ";
        cout<<endl;
    }
    return 0;
}
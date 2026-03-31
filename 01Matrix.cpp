#include <bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> res(n, vector<int>(m, -1));

        // Step 1: Push all 0s and mark distance = 0
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions
        int dr[] = {0, 0, 1, -1};  // R L D U
        int dc[] = {1, -1, 0, 0};

        // Step 2: BFS
        while(!q.empty()) {
            pair<int,int> que = q.front();
            int r = que.first;
            int c = que.second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    if(res[nr][nc] == -1) {
                        res[nr][nc] = res[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return res;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> mat = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    vector<vector<int>> ans = obj.updateMatrix(mat);
    for(auto &row: ans){
        for(auto &ele : row){
            cout<<ele<<" ";
        }
        cout<<"\n";
    }

}
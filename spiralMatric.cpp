#include <bits/stdc++.h>
using namespace std;

class Solution{
public: 
       vector<int> spiralOrder(vector<vector<int>>& matrix) {
		   int m = matrix.size();
		   int n = matrix[0].size();

		   int srow = 0, erow = m-1;
		   int scol = 0, ecol = n-1;
		   vector<int> res;

        while(srow <= erow && scol <= ecol){
          //top
		   for(int i=scol;i<=ecol;i++){
			   res.push_back(matrix[srow][i]);
		   }

           //right
		   for(int i=srow+1;i<=erow;i++){
			   res.push_back(matrix[i][ecol]);
		   }

		   //bottom
		   if(srow < erow){
		       for(int i=ecol-1;i>=scol;i--){
			       res.push_back(matrix[erow][i]);
			   }
		   }

		   //left
		   if(scol < ecol) {
		       for(int i=erow-1;i>=srow+1;i--){
			       res.push_back(matrix[i][scol]);
			   }
		   }

		   srow++; erow--;
		   scol++; ecol--;
		}
		return res;
		  
	   }
    
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    Solution obj;
    vector<int> res = obj.spiralOrder(matrix);

    for(int ele : res){
        cout << ele << " ";
    }
    cout << "END";

    return 0;
}
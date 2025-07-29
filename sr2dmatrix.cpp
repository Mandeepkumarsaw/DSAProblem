#include <bits/stdc++.h>    
using namespace std;


class sr2dmatrix {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();

        int r = 0;
        int c = n - 1;
        while(c>=0 && r <m ) {
            if(target == mat[r][c]) {
                return true;
            } else if (target < mat[r][c]) {
                  c--;
            }
            else {
                   r++;
            }
        }
        return false;
    }
};

int main() {
  sr2dmatrix obj;
  vector<vector<int>> mat = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10, 11, 12}
  };
    cout<<boolalpha<<obj.searchMatrix(mat,6);
    return 0;
}



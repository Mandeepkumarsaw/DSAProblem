#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long TotalSum = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                TotalSum += grid[i][j];
            }
        }

        // if(TotalSum % 2 != 0) return false;   //optimization

        //Horizontal check
           long long BCurrSum = 0;
           for(int i=0;i<m-1;i++){   //logic of m-1(we have to make partition so run till last second Horizontal(same for vertical))
                for(int j=0;j<n;j++){
                    BCurrSum += grid[i][j];
                }
                    if(BCurrSum*2 == TotalSum) return true;               
        }  


        //Vertical check
         long long ACurrSum = 0;
         for(int i=0;i<n-1;i++){    //logic n-1
            for(int j=0;j<m;j++){
                ACurrSum += grid[j][i];
            }
                if(ACurrSum*2 == TotalSum) return true;
        }

        return false;
    }    
        
};

int main(){
    Solution obj;
    vector<vector<int>> grid = {
        {1,4},
        {2,3}
    };

    cout<<boolalpha<<obj.canPartitionGrid(grid);

    return 0;
}
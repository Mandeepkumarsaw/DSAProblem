#include<bits/stdc++.h>
using namespace std;

class ratinmaze {
  public:
   void helper(vector<vector<int>>& mat,int r ,int c,vector<string> &ans,string path) {
       int n = mat.size();
    
       
       if(r<0 || c<0 || r>=n || c>=n  || mat[r][c] == 0 || mat[r][c] == -1) {     //Base Case
           return;
       }
       
       if(r == n-1 && c == n-1) {   //ans
            ans.push_back(path);
       }
       
       
       mat[r][c] = -1;    //visit
       
       helper(mat,r-1,c,ans,path + "U");  //upward
       helper(mat,r+1,c,ans,path + "D"); //downward
       helper(mat,r,c+1,ans,path + "R"); //rightside
       helper(mat,r,c-1,ans,path + "L"); //leftside
       
       mat[r][c] = 1;               //unvisit
       
       
   }
  
    vector<string> ratInMaze(vector<vector<int>>& mat) {
        vector<string> ans;
        string path = "";
        
        helper(mat ,0, 0, ans, path);
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};

int main(){
    ratinmaze obj;
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 1}
    };

    vector<string> res = obj.ratInMaze(mat);

    for(auto& row : res){
        for(char cell: row){
            cout<<cell<<" ";
        }
        cout<<endl;
    }


    return 0;

}
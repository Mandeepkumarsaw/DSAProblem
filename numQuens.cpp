#include<bits/stdc++.h>
using namespace std;

class numQuens {
public:
    bool isSafe(vector<string>& board, int rows, int col, int n) {   //O(n)
        // horizontal
        for (int j = 0; j < n; j++) {
            if (board[rows][j] == 'Q') {
                return false;
            }
        }

        // vertical
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // diagonal(for left above direction)
        for (int i = rows, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // digonal(for right above direction)
        for (int i = rows, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void nQuens(vector<string>& board, int rows, int n,
                vector<vector<string>>& ans) {
        if (rows == n) {
            ans.push_back({board});
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isSafe(board, rows, j, n)) {
                board[rows][j] = 'Q';
                nQuens(board, rows + 1, n, ans);
                board[rows][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));            //Creates a string of length n filled with the character '.'
                                                            //Example: If , this gives n=4  — representing an empty row with no queens.
                                                            //and lastly the syntax---   vector<string> board(n, string(n, '.'));     --it Creates a vector with  elements, each being the string "...."


        vector<vector<string>> ans;

        nQuens(board, 0, n, ans);
        return ans;
    }
};

int main() {
    numQuens obj;
    int n=4;
    vector<vector<string>> res = obj.solveNQueens(n);

    cout<<"First soln: \n";
    
    for (auto val : res) {   //First Loop: Iterates Over Each Solution
    
        for (auto row : val) {   //Second Loop: Iterates Over Each Row in That Configuration
       
            cout << row << endl;
         
        }
        cout <<"Another distinct sol: \n";
    }
   
}
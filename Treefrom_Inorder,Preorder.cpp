#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> res;   

       //helper func of helper fun
    int search(vector<int>& inorder,int st ,int end,int target) {
        for(int i=st;i<=end;i++) {
           if(inorder[i] == target) {
            return i;
           }
        }
        return -1;
    }

    //helper func
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int &preIndex,int left, int right) {
        if(left > right) {
            res.push_back(-1); 
            return NULL;
        }

     TreeNode* root = new TreeNode(preorder[preIndex]);
     res.push_back(preorder[preIndex]);
    

     int idx = search(inorder,left,right,(preorder[preIndex]));
     preIndex++; 

     root->left = helper(preorder,inorder,preIndex,left,idx-1);
     root->right =  helper(preorder,inorder,preIndex,idx+1,right);

     return root;
    }

 
   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
       return helper(preorder,inorder,preIndex,0,inorder.size()-1);
    }

    //arr print
    void arrprint(){

      for(int c : res) {
        cout<<c<<" ";
    }
    cout<<endl;
    }

};

int main() {
    Solution obj;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    obj.buildTree(preorder,inorder);
    obj.arrprint();

    return 0;
}
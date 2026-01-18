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
    vector<string> res;
    void dfs(TreeNode* root,string path) {
        if(!root) return;

        //add curr node value to path
        if(path.empty()) path = to_string(root->val);
        else path += "->" + to_string(root->val);

        //if leaf node, save path
        if(!root->left && !root->right) {
            res.push_back(path);
            return;
        }

        //Recurse
        dfs(root->left,path);
        dfs(root->right,path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return res;
    }

};


      //build tree
     TreeNode* buildTree(vector<int>& order,int &idx) {
     if(idx >= order.size() || order[idx] == -1) {
        idx++;
        return NULL;
     }
   
     TreeNode* root = new TreeNode(order[idx++]);
     root->left = buildTree(order,idx);
     root->right = buildTree(order,idx);

     return root;
    } 

  int main() {
    Solution obj;
    vector<int> tree = {1,2,3,-1,-1,5};
    int idx = 0;
    TreeNode* root = buildTree(tree,idx);

   vector<string> res = obj.binaryTreePaths(root);
   for(const string &path : res) {
    cout<<"'"<<path<<"', ";
   } cout<<endl;
    return 0;
}
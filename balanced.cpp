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
    int checkHeight(TreeNode* root) {
        if(root == NULL) return 0;

        int left = checkHeight(root->left);
        if(left == -1) return -1;

        int right = checkHeight(root->right);
        if(right == -1) return -1;
          
        if(abs(left - right)  > 1) return -1;

        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

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
};


int main() {
   Solution obj;

   vector<int> tree1 = {3,4,1,-1,-1,2,-1,-1,5,-1,-1};
   int idx = 0;

   TreeNode* root = obj.buildTree(tree1,idx);
   cout<<boolalpha<<obj.isBalanced(root);

   return 0;
}   
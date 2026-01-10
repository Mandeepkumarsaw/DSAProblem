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

      bool isIdentical(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL || subRoot==NULL) return root==subRoot;

        bool checkleft = isIdentical(root->left,subRoot->left);
        bool checkright = isIdentical(root->right,subRoot->right);

        return root->val==subRoot->val && checkleft && checkright;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //base case
        if(root == NULL || subRoot == NULL) return root==subRoot;

        if(root->val == subRoot->val && isIdentical(root,subRoot)) return true;

       return isSubtree(root->left,subRoot) ||
        isSubtree(root->right,subRoot);
    }

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
   vector<int> tree2 = {4,1,-1,-1,2,-1,-1};

   int idx1 = 0, idx2 = 0;
   TreeNode* root = obj.buildTree(tree1,idx1);
   TreeNode* subRoot = obj.buildTree(tree2,idx2);

   cout<<boolalpha<<obj.isSubtree(root,subRoot);
   cout<<"! Hence SubRoot is present inside Root & identical. ";
   return 0;
}
#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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


    //Find node
    TreeNode* findNode(TreeNode* root, int val) {
     if(!root) return NULL;
     if(root->val == val) return root;

     TreeNode* leftNode = findNode(root->left,val);
     if(leftNode) return leftNode;
     TreeNode* rightNode =findNode(root->right,val);
     if(rightNode) return rightNode;

    };


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root->val == p->val || root->val == q->val) {
            return root;
        }

        TreeNode* left_LCA = lowestCommonAncestor(root->left,p,q);
        TreeNode* right_LCA = lowestCommonAncestor(root->right,p,q);

        //campare leftCA & rightCA
          
        if(left_LCA && right_LCA) {               //case1 - if both have valid value, then return root of there;
            return root;
        } 
        else if(left_LCA != NULL) {              //case2-if leftCA is valid node & right_CA have NULL node(-1), then return valid Node ie LeftCA
            return left_LCA;
        } else {
            return right_LCA;                   //case3-- if left_CA is NULL node(-1), then return valid node which is right_CA node
        }
    }
};
int main() {
    vector<int> tree = {3,4,1,-1,-1,2,-1,-1,5,-1,-1};
    int idx = 0;
    TreeNode* root = buildTree(tree,idx);

    TreeNode* p = findNode(root,2);
    TreeNode* q = findNode(root,5);
    Solution obj;
    TreeNode* res = obj.lowestCommonAncestor(root,p,q);

    cout<<"Lowest Common Ancestor: "<<res->val;

   return 0;
}
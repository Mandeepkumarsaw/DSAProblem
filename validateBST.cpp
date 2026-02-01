#include<iostream>
#include<vector>
using namespace std;


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
   bool helper(TreeNode* root,TreeNode* min,TreeNode* max){
     if(root == NULL) return true;

        if(min != NULL && root->val <= min->val) return false;
        if(max != NULL && root->val >= max->val) return false;
        
        return helper(root->left,min,root) &&
               helper(root->right,root,max);
   }


    bool isValidBST(TreeNode* root) {
       return helper(root,NULL,NULL);
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

int main(){
    Solution obj;      //root,left,right
    vector<int> order = {2,1,-1,-1,3,-1,-1};
    int idx=0;
    TreeNode* root = buildTree(order,idx);

    if(obj.isValidBST(root)){
        cout<<"BST";
    } else {
        cout<<"Not a BST";
    }
}
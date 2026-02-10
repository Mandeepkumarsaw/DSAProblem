#include <iostream>
#include <vector>
#include <algorithm>
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
    void inTraverse(TreeNode* root,vector<int>& inorder){
        if(!root) return;
        inTraverse(root->left,inorder);
        inorder.push_back(root->val);
        inTraverse(root->right,inorder);
    }
    TreeNode* ConstructBalancedBST(vector<int>& In,int low,int high) {
      if(low > high) return NULL;

      int mid = low + (high - low)/2;
      TreeNode* root = new TreeNode(In[mid]);
      root->left = ConstructBalancedBST(In,low,mid-1);
      root->right =ConstructBalancedBST(In,mid+1,high);

      return root;
    }
   

//Main func
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;
        vector<int> Inorder;
        inTraverse(root,Inorder);

        return ConstructBalancedBST(Inorder,0,Inorder.size()-1);
    }


    //print BST

     void print(TreeNode* root){
        if(!root) return;
        print(root->left);
        cout<<root->val<<" ";
        print(root->right);
    }
};

int main() {
   
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(20);
    root->right->right->right = new TreeNode(25);

    Solution obj;
    cout<<"Original BST(inorder):  ";
    obj.print(root);
    cout<<endl;

   TreeNode* newRoot = obj.balanceBST(root);
   cout<<"Balanced BST(inorder) ";
   obj.print(newRoot);
   cout<<endl;

   return 0;

}
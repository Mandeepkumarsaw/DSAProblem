#include <bits/stdc++.h>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        
        while(curr != NULL){
            if(curr->left == NULL){
                res.push_back(curr->val);
                curr=curr->right;
            }
            else{
                 TreeNode* IP = curr->left;
                   while(IP->right != NULL && IP->right != curr) {
                       IP = IP->right;
                    }
                if(IP->right == NULL){
                    IP->right = curr;
                    curr=curr->left;
                     

                } else {
                    IP->right = NULL;
                    res.push_back(curr->val);
                    curr=curr->right;

                }
            }
        }

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
    vector<int> order = {1,-1,2,3};
    int idx=0;
    TreeNode* root = buildTree(order,idx);

    vector<int> res = obj.inorderTraversal(root);
    for(int c: res){
        cout<<c<<" ";
    } cout<<endl;

   return 0;
}
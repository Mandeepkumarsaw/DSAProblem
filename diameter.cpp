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



class Solution {
public:
//Main func
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }

//Helper func
   int ans = 0;
   int height(TreeNode* root) {
    if(root == NULL) return 0;

     int left_Ht =  height(root->left) ;
     int right_Ht = height(root->right);
     ans = max(ans,left_Ht + right_Ht);  

     return max(left_Ht , right_Ht) + 1;
   }    
};

int main() {
    Solution obj;
    vector<int> order = {1,2,4,-1,-1,5,-1,-1,3,-1,-1};
    int idx = 0;
    TreeNode* root = buildTree(order,idx);

    cout<<"Diameter of BT: "<<obj.diameterOfBinaryTree(root);

    return 0;
}
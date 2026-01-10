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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL) return p==q;
        
       bool checkleft =  isSameTree(p->left,q->left);
        bool checkright = isSameTree(p->right,q->right);

        return checkleft && checkright && p->val == q->val;
    }
};


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
   vector<int> p = {1,2,-1,-1,3,-1,-1};
   vector<int> q = {1,2,-1,-1,3,-1,-1};

   int idx1 = 0, idx2 = 0;
   TreeNode* p_root = buildTree(p,idx1);
   TreeNode* q_root = buildTree(q,idx2);

   Solution obj;
   bool res = obj.isSameTree(p_root,q_root);
   cout<<boolalpha<<res<<"! It's identical.";

   return 0;
}
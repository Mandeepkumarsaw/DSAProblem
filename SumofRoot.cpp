#include <bits/stdc++.h>
#include <cmath>
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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,0);
    }
private:   
    int dfs(TreeNode* node,int curr){
        if (!node)  return 0;
        // curr = (curr<<1) | node->val;   //OR is used to add new bits at end ie 1,10,101,,etc
        curr = (2*curr) + node->val;
        if(!node->left && !node->right) return curr;
        return dfs(node->left,curr)+dfs(node->right,curr);
    } 
};

int main() {
    // Example tree:
    //       1
    //      / \
    //     0   1
    //    / \   \
    //   0   1   1
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(1);

    Solution sol;
    cout<<"Sum of root-to-leaf binary numbers: " << sol.sumRootToLeaf(root) << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

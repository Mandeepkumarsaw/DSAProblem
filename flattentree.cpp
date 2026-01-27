
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
    TreeNode* RecentNode = NULL;
    void flatten(TreeNode* root) {
     if(root == NULL) return;

     flatten(root->right);   
     flatten(root->left);

    
     root->left = NULL;
     root->right = RecentNode;
     RecentNode = root;   
    }
    
};
// Helper function to print flattened tree
void printFlattened(TreeNode* root) {
    while(root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    // Build a sample tree:
    //        1
    //       / \
    //      2   5
    //     / \   \
    //    3   4   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution obj;
    obj.flatten(root);

    cout << "Flattened tree (linked list form): ";
    printFlattened(root);

    return 0;
}

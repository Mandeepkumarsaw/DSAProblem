#include<bits/stdc++.h>
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
    vector<int> res;
    void DFS(TreeNode* root,int depth){
        if(!root) return;

        if(depth == res.size()){    //first come at curr level
            res.push_back(root->val);
        }else {
            res[depth] = max(res[depth],root->val);
        }

        DFS(root->left,depth+1);
        DFS(root->right,depth+1);
    }
    vector<int> largestValues(TreeNode* root) {
        DFS(root,0);

        return res;
    }
};

int main(){
    // Build a sample tree:
    //        1
    //       / \
    //      3   2
    //     / \   \
    //    5   3   9

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution obj;
    vector<int> ans = obj.largestValues(root);

    cout << "Largest values at each level: ";
    for(int x : ans) cout << x << " ";
    cout << endl;

    return 0;
     
}
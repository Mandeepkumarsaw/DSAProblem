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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode*,unsigned long long >> q;
        q.push({root,0});
        int maxWidth = 0;

        while(!q.empty()) {
            int currLevelSize = q.size();
            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;
            maxWidth = max(maxWidth,(int)(endIdx-stIdx+1));

            for(int i=0; i<currLevelSize; i++) {
                auto curr = q.front();
                q.pop();

            unsigned long long idx = curr.second - stIdx; 
                // normalize to avoid overflow

              if(curr.first->left)  {
                q.push({curr.first->left,(2*idx+1)});
              } 
              if(curr.first->right) {
                 q.push({curr.first->right,(2*idx+2)});
              }
              
            }
        }
        return maxWidth;
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
    vector<int> tree = {1,3,2,5,-1,-1,9,6,-1,7};
    int idx = 0;
    TreeNode* root = buildTree(tree,idx);

    int res = obj.widthOfBinaryTree(root);
    cout<<"Max width among all levels: "<<res;

    return 0;
}    
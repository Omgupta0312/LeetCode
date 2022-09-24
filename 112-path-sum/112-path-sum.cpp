/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root, int t)
    {
        if(root!=NULL && t-root->val==0 && root->left==NULL && root->right==NULL){
            return 1;
        }
        if(root==NULL)
            return false;
        
        return helper(root->left,t-root->val) || helper(root->right,t- root->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root,targetSum);
      
    }
};
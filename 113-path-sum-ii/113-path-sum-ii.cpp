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
    void helper(TreeNode* root, int t,vector<int> &v,vector<vector<int>> &ans)
    {
        if(root!=NULL && t-root->val==0 && root->left==NULL && root->right==NULL)
        {
            v.push_back(root->val);
            ans.push_back(v);
            v.pop_back();
            return;
        }
        if(root==NULL)
            return;
        
        v.push_back(root->val);
        helper(root->left,t-root->val,v,ans);
        helper(root->right,t- root->val,v,ans);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int> v;
        helper(root,targetSum,v,ans);
        return ans;
    }
};
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
    unordered_map<int,int> m;
    bool helper(TreeNode *root,int k)
    {
        if(root==NULL)
            return false;
        
        if(m.find(k-root->val)!=m.end())
            return true;
        m[root->val]++;
       return helper(root->left,k) || helper(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        return helper(root,k);
    }
};
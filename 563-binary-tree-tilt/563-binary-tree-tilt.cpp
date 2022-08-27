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
    int helper(TreeNode *root,int &ans)
    {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL)
        {
            int t=root->val;
            root->val = 0;
            return t;
        }
        
        int la = helper(root->left,ans);
        int ra = helper(root->right,ans);
        
        int x = root->val;
        root->val = abs(la-ra);
        ans+=root->val;
        return x + la + ra;
    }
    int findTilt(TreeNode* root) {
        int ans=0;
        int ret=helper(root,ans);
        return ans;
    }
};
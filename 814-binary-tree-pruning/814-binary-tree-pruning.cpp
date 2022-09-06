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
    
    int helper(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        
        int ls = helper(root->left);
        int rs = helper(root->right);
        
        if(ls==0)
            root->left=NULL;
        if(rs==0)
            root->right=NULL;
        
        return (root->val==1?1:0) + (ls+rs);
    }
    TreeNode* pruneTree(TreeNode* root) {
        int x = helper(root);
        if(x==0)
            return NULL;
        return root;
//         if(root==NULL)
//             return root;
        
//         root->left=pruneTree(root->left);
//         root->right=pruneTree(root->right);
//         if(root->val==0 && root->left==NULL && root->right==NULL)
//             return NULL;
        
//         return root;
    }
};
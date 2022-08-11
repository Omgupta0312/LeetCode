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
//     bool helper(TreeNode *root,int lmax,int rmin)
//     {
//         if(root->left==NULL && root->right==NULL)
//             return true;
        
//         bool f1 = helper(root->left,lmax,rmin);
//         bool f2 = helper(root->right,lmax,rmin);
        
//         if()
//     }
    bool helper(TreeNode* root,long long int &prev)
    {
        if(root==NULL) return true;
        bool f1 = helper(root->left,prev);
        if(!f1) return f1;
        
        if(prev<root->val && root->val>=INT_MIN && root->val<=INT_MAX) prev=root->val; 
        else return false;
        
        return helper(root->right,prev);
    }
    bool isValidBST(TreeNode* root) {
        long long int prev=LLONG_MIN;
        return helper(root,prev);
    }
};
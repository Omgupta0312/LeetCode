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
    bool helper1(TreeNode *root,long long int s,long long int e)
    {
        if(root==NULL)
            return true;
        if(root->val > s && root->val < e)  
             return helper1(root->left,s,root->val) && helper1(root->right,root->val,e);
        else return false;
        
       
    }
    bool helper2(TreeNode* root,long long int &prev)
    {
        if(root==NULL) return true;
        bool f1 = helper2(root->left,prev);
        if(!f1) return f1;
        
        if(prev<root->val && root->val>=INT_MIN && root->val<=INT_MAX) prev=root->val; 
        else return false;
        
        return helper2(root->right,prev);
    }
    bool isValidBST(TreeNode* root) {
        // long long int prev=LLONG_MIN;
        // return helper2(root,prev);
        long long int s=LLONG_MIN,e=LLONG_MAX;
        return helper1(root,s,e);
    }
};
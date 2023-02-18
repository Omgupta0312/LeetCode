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
    bool helper(TreeNode* root,int n,int d,pair<TreeNode*,int> &p){
        if(root==NULL) return false;
        
        if((root->left!=NULL && root->left->val == n) || (root->right!=NULL && root->right->val == n)){
            p = {root,d+1};
            return true;
            
        }
        return helper(root->left,n,d+1,p) ||  helper(root->right,n,d+1,p);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        pair<TreeNode*,int> p1{NULL,INT_MAX},p2{NULL,INT_MAX};
        if(!helper(root,x,1,p1) || !helper(root,y,1,p2)){
            return false;
        }
        
        if(p1.first == p2.first || p1.second != p2.second) 
            return false;
        
        return true;
    }
};
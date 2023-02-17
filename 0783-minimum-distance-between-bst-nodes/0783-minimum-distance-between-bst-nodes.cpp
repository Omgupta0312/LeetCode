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
    
    void helper(TreeNode *root,vector<int> &v){
        if(root==NULL){
            return ;
        }
        
        helper(root->left,v);
        v.emplace_back(root->val);
        helper(root->right,v);
        
       
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        helper(root,v);
        int ans=INT_MAX;
        for(auto x = 0;x<v.size();x++){
            for(auto y = 0;y<v.size();y++){
                if(x!=y)
                    ans = min(ans , abs(v[x]-v[y]));
            }
        }
        return ans;
    }
};
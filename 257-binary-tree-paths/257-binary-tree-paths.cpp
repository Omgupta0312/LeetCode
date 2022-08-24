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
    void helper(TreeNode *root,vector<string>&ans,vector<int> &v)
    {
        if(root==NULL)
            return;
        
        if(root->left ==NULL && root->right==NULL)
        {
            v.push_back(root->val);
            string t="";
            for(int i=0;i<v.size();i++)
            {
                t+=to_string(v[i]);
                if(i<v.size()-1)
                    t+="->";
            }
            ans.push_back(t);
            v.pop_back();
            return;
        }
        
    
        v.push_back(root->val);
        helper(root->left,ans,v);
        helper(root->right,ans,v);
        v.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        vector<int> v;
        helper(root,ans,v);
        return ans;
    }
};
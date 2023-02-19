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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back({root->val});
        
        int level = 0;
        while(!q.empty()){
            vector<TreeNode*> ref;
            vector<int> values;
            level++;
            int size = q.size();
            while(size--)
            {
                TreeNode *front = q.front();
                q.pop();
                if(front->left!=NULL){
                    q.push(front->left);
                    values.push_back(front->left->val);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                    values.push_back(front->right->val);
                }
            }
            
            
            int n = ref.size();
            if(level%2){
                reverse(values.begin(),values.end());
            }
            if(values.size()!=0) 
                ans.push_back(values);
            
        }
        return ans;
    }
};
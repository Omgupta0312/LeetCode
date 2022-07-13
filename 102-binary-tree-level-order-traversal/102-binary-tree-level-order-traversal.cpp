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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        
        if(root==NULL)
            return v;
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> a;
        a.push_back(q.front()->val);
        v.push_back(a);
        a.pop_back();
        q.push(NULL);
        
        while(q.empty()==false)
        {
            TreeNode* front = q.front();
            q.pop();
            
            if(front==NULL)
            {
                if(a.size()>0)
                {
                    v.push_back(a);
                    a.clear();
                }
                
                if(q.empty()==false)
                {
                    q.push(NULL);
                }
            }            
         
            else{
               if(front->left!= NULL)
               {
                   q.push(front->left);
                   a.push_back(front->left->val);
               }
                
               if(front->right!= NULL)
               {
                   q.push(front->right);
                   a.push_back(front->right->val);
               }
        
            }    
            
        }
       
        return v;
    }
};
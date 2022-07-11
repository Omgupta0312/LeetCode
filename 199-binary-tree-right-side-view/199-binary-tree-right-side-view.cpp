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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> a;
        if(root==NULL)
            return a ;
        
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        a.push_back(q.front()->val);
        v.push_back(a.back());
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
                    v.push_back(a.back());
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
   
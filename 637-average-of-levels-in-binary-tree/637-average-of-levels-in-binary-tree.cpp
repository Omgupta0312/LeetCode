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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        vector<double> ans;
        if(root==NULL)
            return ans;
        
        q.push(root);
        q.push(NULL);
        double cls=0;
        int count=0;
        while(q.empty()==false)
        {
            
            TreeNode* f = q.front();
            q.pop();
            if(f==NULL)
            {
                cls/=count;
                ans.push_back(cls);
                cls=0,count=0;
                cout<<endl;
                if(q.empty()==false)
                    q.push(NULL);
            }
            else{
                cls+=f->val;
                count++;
                cout<<f->val<<" ";
                if(f->left!=NULL)
                q.push(f->left);
                if(f->right!=NULL)
                q.push(f->right);
            }
            
        }
        return ans;
    }
};
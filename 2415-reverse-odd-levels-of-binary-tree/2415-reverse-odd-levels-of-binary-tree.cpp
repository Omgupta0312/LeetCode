class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            vector<TreeNode*> ref;
            vector<int> values;
            level++;
            while(!q.empty())
            {
                TreeNode *front = q.front();
                q.pop();
                if(front->left!=NULL){
                    ref.push_back(front->left);
                    values.push_back(front->left->val);
                }
                if(front->right!=NULL){
                    ref.push_back(front->right);
                    values.push_back(front->right->val);
                }
            }
            
            
            int n = ref.size();
            for(auto i=0;i<n;i++){
                if(level%2) ref[i]->val = values[n-i-1];
                q.push(ref[i]);
            }
            
        }
        return root;
    }
};
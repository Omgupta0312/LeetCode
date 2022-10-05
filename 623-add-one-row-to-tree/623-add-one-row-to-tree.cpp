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
    TreeNode* helper(TreeNode* root,int &val,int &depth,int currdepth,bool f)
    {
        if(currdepth==depth)
        {
            TreeNode *temp=new TreeNode(val);
            if(f){
                temp->right=root;
            }else{
                temp->left=root;
            }
            return temp;
        }
        
        if(root!=NULL){
            root->left=helper(root->left,val,depth,currdepth+1,0);
            root->right=helper(root->right,val,depth,currdepth+1,1);
        }
        return root;
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
       return helper(root,val,depth,1,0);
    }
};
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
    TreeNode *helper(vector<int>& nums,int l,int h)
    {
        if(l<=h){
            int mid=l+(h-l)/2;
            TreeNode *root =new TreeNode(nums[mid]);

            root->right = helper(nums,mid+1,h);
            root->left = helper(nums,l,mid-1);

            return root;
      }  
        else
            return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return helper(nums,0,nums.size()-1);
        
    }
};
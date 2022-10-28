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
    TreeNode* helper(vector<int>&nums,int l,int h){
        if(l<=h)
        {
            int mxi=-1,mv=INT_MIN;
            for(int i=l;i<=h;i++){
                if(nums[i]>mv)
                {
                    mv=nums[i];
                    mxi=i;
                }
            }
            
            TreeNode *temp = new TreeNode(nums[mxi]);
            temp->left = helper(nums,l,mxi-1);
            temp->right= helper(nums,mxi+1,h);
            return temp;
        }
        return NULL;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};
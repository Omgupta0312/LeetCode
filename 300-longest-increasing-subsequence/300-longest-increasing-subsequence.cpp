class Solution {
public:
    int helper(vector<int>&nums,int i,int pi,vector<vector<int>>&v)
    {
        if(i==nums.size()) return 0;
        if(v[i][pi+1]!=-1) return v[i][pi+1];
        
        int len=helper(nums,i+1,pi,v);
        if(pi == -1 || nums[pi]<nums[i])
            len=max(len,1+helper(nums,i+1,i,v));
        
        return v[i][pi+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>v(nums.size(),vector<int>(nums.size()+1,-1));
        return helper(nums,0,-1,v);
    }
};
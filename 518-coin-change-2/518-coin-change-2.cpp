class Solution {
public:
     int helper(vector<int> &nums, int i,int x,vector<vector<int>>&dp)
    {
        if(i==0)
        {
            return x%nums[0]==0;
        }
        if(dp[i][x]!=-1) return dp[i][x];

        int nottake = helper(nums,i-1,x,dp);
        int take=0;
        if(nums[i]<=x)
            take = helper(nums,i,x-nums[i],dp);

        return dp[i][x] = nottake + take;
    }

    
    int change(int x, vector<int>& nums) {
         vector<vector<int>>dp(nums.size(),vector<int>(x+1,-1));
        int ans = helper(nums,nums.size()-1,x,dp);
       return ans;
    }
};
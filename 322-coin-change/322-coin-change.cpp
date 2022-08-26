class Solution {
public:
    int helper(vector<int> &nums, int i,int x,vector<vector<int>>&dp)
    {
        if(i==0)
        {
            if(x%nums[i]==0) return x/nums[i];
            else return 1e9;
        }
        if(dp[i][x]!=-1) return dp[i][x];

        int nottake = helper(nums,i-1,x,dp);
        int take=1e9;
        if(nums[i]<=x)
            take = 1 + helper(nums,i,x-nums[i],dp);

        return dp[i][x] = min(nottake,take);
    }

    int coinChange(vector<int>& nums, int x) {
        vector<vector<int>>dp(nums.size(),vector<int>(x+1,-1));
        int ans = helper(nums,nums.size()-1,x,dp);
        return ans!=1e9?ans:-1;
    }
};
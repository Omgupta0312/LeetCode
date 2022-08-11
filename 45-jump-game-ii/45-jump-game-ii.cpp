class Solution {
public:
    int helper(vector<int>&nums,int idx,vector<int>&dp)
    {
        if(dp[idx]!=-1)
            return dp[idx];
        
        int ans=INT_MAX;
        for(int i=1;i<=nums[idx];i++)
            if(idx+i < nums.size()) ans = min(ans, helper(nums,idx+i,dp));
            else break;
        
        return dp[idx] = ans != INT_MAX ? ans+1 : INT_MAX;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        dp[nums.size()-1]=0;
    
        int ans= helper(nums,0,dp);
        for(auto x:dp)cout<<x<<" ";
        return ans;
    }
};
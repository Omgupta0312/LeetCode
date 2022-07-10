class Solution {
public:
    
    int helper(vector<int>& v,int i,vector<int>&dp)
    {
        if(i>=v.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        return dp[i] = min(helper(v,i+2,dp),helper(v,i+1,dp)) + v[i];
        
            
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(3001,-1);
        return min(helper(cost,0,dp),helper(cost,1,dp));
    }
};
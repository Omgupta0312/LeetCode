class Solution {
public:
    int helper(vector<int>&v,int b,int i,vector<vector<int>>& dp){
        if(i==v.size())
            return 0;
        
        if(dp[i][b]!=-1)
            return dp[i][b];
        
        int profit = -1e8;
        if(b){
            profit = max(-v[i]+helper(v,0,i+1,dp) , 0 + helper(v,1,i+1,dp));
        }
        else{
            profit = max(v[i]+helper(v,1,i+1,dp) , 0 + helper(v,0,i+1,dp));
        }
        
        return dp[i][b]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper(prices,1,0,dp);
    }
};
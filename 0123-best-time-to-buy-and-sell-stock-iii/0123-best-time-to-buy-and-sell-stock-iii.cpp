class Solution {
public:
    int helper(vector<int>&v,int b,int i,int c,vector<vector<vector<int>>>& dp){
        if(i==v.size() || c==0)
            return 0;
        
        if(dp[i][b][c]!=-1)
            return dp[i][b][c];
        
        int profit = -1e8;
        if(b){
            profit = max(-v[i]+helper(v,0,i+1,c,dp) , 0 + helper(v,1,i+1,c,dp));
        }
        else{
            profit = max(v[i]+helper(v,1,i+1,c-1,dp) , 0 + helper(v,0,i+1,c,dp));
        }
        
        return dp[i][b][c]=profit;
    }
  
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(prices,1,0,2,dp);
    }
};
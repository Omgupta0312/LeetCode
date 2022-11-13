class Solution {
public:
//     int helper(vector<int>&v,int b,int i,int c,vector<vector<vector<int>>>& dp){
//         if(i==v.size() || c==0)
//             return 0;
        
//         if(dp[i][b][c]!=-1)
//             return dp[i][b][c];
        
//         int profit = -1e8;
//         if(b){
//             profit = max(-v[i]+helper(v,0,i+1,c,dp) , 0 + helper(v,1,i+1,c,dp));
//         }
//         else{
//             profit = max(v[i]+helper(v,1,i+1,c-1,dp) , 0 + helper(v,0,i+1,c,dp));
//         }
        
//         return dp[i][b][c]=profit;
//     }
  
//     int maxProfit(vector<int>& prices) {
//         vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
//         return helper(prices,1,0,2,dp);
//     }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=prices.size()-1;i>=0;i--)
        {
            for(int b=0;b<=1;b++)
            {
                for(int c=1;c<=2;c++)
                {
                    int profit = -1e8;
                    if(b){
                        profit = max(-prices[i]+dp[i+1][0][c] , 0 + dp[i+1][1][c]);
                    }
                    else{
                        profit = max(prices[i]+dp[i+1][1][c-1] , 0 + dp[i+1][0][c]);
                    }

                   dp[i][b][c]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};
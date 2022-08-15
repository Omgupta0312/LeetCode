class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                    int right=INT_MAX, down=INT_MAX;
                    if(i>0) down=grid[i][j]+dp[i-1][j];
                    if(j>0) right=grid[i][j] + dp[i][j-1];
                    
                    dp[i][j]=min(right,down);
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};
class Solution {
public:
    int helper(int i,int j1,int j2,int n,int c, vector<vector<int>> &g, vector<vector<vector<int>>> &dp)
{
    if(j1<0 || j1>=c || j2<0 || j2>=c) return -1e8;
    if(i==n-1)
    {
        if(j1==j2) return g[i][j1];
        else return g[i][j1]+g[i][j2];
    }
    
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    int maxi=INT_MIN;
    for(int dj1=-1;dj1<=1;dj1++)
    {
        for(int dj2=-1;dj2<=1;dj2++)
        {
            int value=0;
            if(j1==j2) value = g[i][j1];
            else value = g[i][j1]+g[i][j2];
            value += helper(i+1,j1+dj1,j2+dj2,n,c,g,dp);
            maxi=max(maxi,value);
        }
    }
    return dp[i][j1][j2]=maxi;
}

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return helper(0,0,m-1,n,m,grid,dp);
    }
};
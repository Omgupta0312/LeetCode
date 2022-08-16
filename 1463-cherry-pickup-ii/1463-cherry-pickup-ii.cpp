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
              
//************MEMORISATION APPROARCH:************
        // return helper(0,0,m-1,n,m,grid,dp);
        
        
//************TABAULATION APPROARCH:************
        
        for(int j1=0;j1<m;j1++)
            for(int j2=0;j2<m;j2++){
                  if(j1==j2) dp[n-1][j1][j2]=grid[n-1][j1];
                  else dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j1=0; j1<m; j1++)
            {
                for(int j2=0; j2<m; j2++)
                {
                    int maxi=INT_MIN;
                    for(int dj1=-1;dj1<=1;dj1++){
                        for(int dj2=-1;dj2<=1;dj2++){
                            int value=0;
                            if(j1==j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1]+grid[i][j2];
                            
                            if(dj1+j1<m && dj2+j2<m && dj1+j1>=0 && dj2+j2>=0)
                                value += dp[i+1][dj1+j1][dj2+j2];
                            else 
                                value = INT_MIN;
                            
                            maxi=max(maxi,value);
                        }
                    }
                    dp[i][j1][j2]=maxi;
                }
            }
        }
        
        return dp[0][0][m-1];

    }
};
class Solution {
public:
   
    const unsigned int mod=1000000007;
    int helper(string &s,string &t,int i,int j,vector<vector<int>> &dp)
    {
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j]) 
            return dp[i][j] = (helper(s,t,i-1,j-1,dp)%mod + helper(s,t,i-1,j,dp)%mod)%mod;
        else
            return dp[i][j] = helper(s,t,i-1,j,dp)%mod;
    }
   
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return helper(s,t,s.size()-1,t.size()-1,dp)%mod;
    }
};
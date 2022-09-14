class Solution {
public:
    int helper(string &s,string &t,int i ,int j,vector<vector<int>> &dp)
    {
        if(i==0 || j==0) 
            return 0;
        if(dp[i][j]!=-1) 
            return dp[i][j];
        if(s[i-1]==t[j-1]) 
            return dp[i][j] = 1+helper(s,t,i-1,j-1,dp);

        return dp[i][j] = max(helper(s,t,i-1,j,dp),helper(s,t,i,j-1,dp));
    }

    

    string shortestCommonSupersequence(string &s, string &t) {
         vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
         int lcs = helper(s,t,s.size(),t.size(),dp);
         string ans="";
         int i=s.size(),j=t.size();
     while(i>0 && j>0)
     {
         if(s[i-1]==t[j-1])
         {
             ans+=s[i-1];
             i--;j--;
         }
         else if(dp[i-1][j]>dp[i][j-1])
         {
             ans+=s[i-1];
             i--;
         }
         else{
             ans+=t[j-1];
             j--;
         }
     }
    while(i>0){
        ans+=s[i-1];
        i--;
    }
    while(j>0){
        ans+=t[j-1];
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
         
    }
};
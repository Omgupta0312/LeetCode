class Solution {
public:
    int findLength(vector<int>& s, vector<int>& t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));
        int ans=INT_MIN;
        for(int i=1;i<s.size()+1;i++)
        {
            for(int j=1;j<t.size()+1;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans==INT_MIN?0:ans;
    }
};
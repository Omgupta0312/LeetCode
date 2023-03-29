class Solution {
public:
    int helper(vector<int> &s,int i,int ind,vector<vector<int>> &dp){
        if(i==s.size()) return 0;
        
        if(dp[i][ind]!=-1) return dp[i][ind];
        
        int take = s[i]*ind + helper(s,i+1,ind+1,dp);
        int nottake = helper(s,i+1,ind,dp);
        
        return dp[i][ind] = max(take,nottake);
    }
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        if(s.size()>0 && s[0]<0 && s.back()<0) return 0;
        vector<vector<int>> v(s.size()+1,vector<int>(s.size()+1,-1));
        
        
        return helper(s,0,1,v);
    }
};
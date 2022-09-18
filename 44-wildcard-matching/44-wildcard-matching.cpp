class Solution {
public:
    bool isMatch(string t, string s) {
        int n=s.size(),m=t.size();
        vector<bool> prev(m+1,0);
        prev[0]=1;

        for(int i=1;i<=n;i++)
        { 
             vector<bool> curr(m+1,0);
             bool flag = true;
             for(int x=1;x<=i;x++)
                if(s[x-1]!='*'){
                    flag=false;break;
                }
             curr[0]=flag;

            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1] || s[i-1]=='?')
                    curr[j] = prev[j-1];
                else if(s[i-1]=='*')
                    curr[j] = prev[j] || curr[j-1];
                else 
                    curr[j] = false;
            }
            prev=curr;
        }
        return prev[m];
    
    
    }
};
class Solution {
public:
    int findLength(vector<int>& s, vector<int>& t) {
        vector<int>prev(t.size()+1,0),curr(t.size()+1,0);
        int ans=INT_MIN;
        for(int i=1;i<s.size()+1;i++)
        {
            for(int j=1;j<t.size()+1;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    curr[j]=prev[j-1]+1;
                    ans=max(ans,curr[j]);
                }
                else
                    curr[j]=0;
            }
            prev=curr;
        }
        return ans==INT_MIN?0:ans;
    }
};
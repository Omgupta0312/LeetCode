class Solution {
public:
    int partitionString(string s) {
        vector<int> v(26,0);int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(v[s[i]-97]!=0)
            {
                ans++;
                for(auto &x:v)
                    x=0;
                
            }
            v[s[i]-97]=1;
        }
        return ans+1;
    }
};
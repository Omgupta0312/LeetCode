class Solution {
public:
    int firstUniqChar(string s) {
        int ans=-1;
        vector<int>v(26,0);
        for(int i=s.size()-1;i>=0;i--)
            v[s[i]-97]++;
        
        for(int i=0;i<s.size();i++)
            if(v[s[i]-97]==1)
                return i;
        
        return -1;
    }
};
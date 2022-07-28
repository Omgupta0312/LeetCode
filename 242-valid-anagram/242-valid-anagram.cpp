class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        
        int a[26]={0};
        for(int i=0;i<s.size();i++)
            a[s[i]-97]++;
        for(int i=0;i<t.size();i++)
            a[t[i]-97]--;
        
        for(auto &x:a)
            if(x!=0) return false;
        return true;
    }
};
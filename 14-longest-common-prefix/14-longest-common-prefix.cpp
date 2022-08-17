class Solution {
public:
    string check(string &s,string &p)
    {
        string ans="";
        int i=0,j=0;
        while(i<s.size()&&j<p.size())
        {
            if(s[i]==p[j])
                ans+=s[i];
            else break;
            i++;
            j++;
        }
        return ans; 
    }
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string t=strs[0];
        for(int i=1;i<strs.size();i++)
        {
            t = check(strs[i],t);
            if(t=="")
                return t;
           
        }
        return t;
    }
};
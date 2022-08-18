class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>m;
        for(auto x:t)
            m[x]++;
        
        for(auto x:s)
            m[x]--;
        
        for(auto x:t)
            if(m[x]==1)
                return x;
        return ' ';
    }
};
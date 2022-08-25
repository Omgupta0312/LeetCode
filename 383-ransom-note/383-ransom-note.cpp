class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>v(26,0);
        for(auto &x:magazine)
            v[x-97]++;
        
        for(auto &x:ransomNote)
        {
            if(v[x-97]==0)
                return false;
            
            v[x-97]--;
                
        }
        return true;
    }
};
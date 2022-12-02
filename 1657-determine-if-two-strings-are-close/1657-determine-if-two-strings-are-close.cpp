class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        
        vector<int> v(26,0);
        for(int i=0;i<word1.size();i++)
             v[word1[i]-97]=1;
        for(int i=0;i<word2.size();i++)
             v[word2[i]-97]=0;
        

        
        for(auto &x:v)
            if(x!=0) return false;
        
        unordered_map<char,int> m1,m2;
        unordered_map<int,int> m;
        for(int i=0;i<word1.size();i++)
        {
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
        
        for(auto &x:m1){
            m[x.second]++;
        }
        
        for(auto &x:m2){
            m[x.second]--;
        }
        
        for(auto &x:m){
            if(x.second != 0)
                return false;
        }
        return true;
    }
};
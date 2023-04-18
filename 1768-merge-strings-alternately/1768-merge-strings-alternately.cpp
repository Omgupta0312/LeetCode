class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        string ans="";
        bool f=1;
        while(i<word1.size() && j<word2.size()){
            if(f){
                ans+=word1[i++];
                f=!f;
            }else{
                ans+=word2[j++];
                f=!f;
            }
        }
        
        ans+=word1.substr(i);
        ans+=word2.substr(j);
        return ans;
    }
};
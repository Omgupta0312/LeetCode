bool comp(string &s1, string &s2)
{
    return s1.size()<s2.size();
}
class Solution {
public:
    bool checkPoss(string &s1 , string &s2){
        if(s1.size()!=s2.size()+1) return false;
        int first = 0;
        int second = 0;
        while(first < s1.size()){
            if(s1[first] == s2[second])
            {
                first ++;second++;
            }else{
                first++;
            }
        }
        return (first == s1.size() && second == s2.size()) ;
    }
    int longestStrChain(vector<string>& words) {
        vector<int> dp(words.size(),1);
        int maxi=1;
        int lastIndex = 0;
        sort(words.begin(),words.end(),comp);
        for(int i=0;i<words.size();i++)
        {
            for(int prev = 0 ;prev <i;prev++)
            {
                if(checkPoss(words[i],words[prev] ) && 1+ dp[prev] > dp[i])
                {
                    dp[i] = 1 +dp[prev];
            
                }
            }
            
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        return maxi;
      
    }
};
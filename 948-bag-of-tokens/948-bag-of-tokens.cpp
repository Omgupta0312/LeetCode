class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int ans=0,curr=0;
        int i=0,j=tokens.size()-1;
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                power-=tokens[i];
                curr++;
                i++;
            }
            else if(power<tokens[i] && curr>0)
            {
                ans=max(ans,curr);
                curr--;
                power+=tokens[j];
                j--;
            }
            else if(curr==0)
            {
                 j--;
                 i++;
            }
            
        }
        ans=max(ans,curr);
        return ans<0?0:ans;
    }
};
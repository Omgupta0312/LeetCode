class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int prev=0,ans=0;
        for(int i=1;i<colors.size();i++)
        {
            if(colors[prev]==colors[i])
            {
                if(neededTime[prev]>neededTime[i])
                {
                    ans+=neededTime[i];
                    // cout<<i<<" -- "<<endl;
                }
                else{
                    ans+=neededTime[prev];
                    prev=i;
                    // cout<<i<<endl;
                }
            }
            else{
                prev=i;
            }
        }
        return ans;
    }
};
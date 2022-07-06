class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        unsigned int sum=0,currsum=0;
        for(int i=0;i<cards.size();i++)
           sum+=cards[i];
        
        if(k==cards.size())
            return sum;
        
        int res=0,n=cards.size();
        for(int i=0;i<n-k;i++)
            currsum+=cards[i];
        
        res=max<unsigned int>(res,sum-currsum);
        for(int i=0;i<k;i++)
        {
            currsum+=cards[n-k+i]-cards[i];
            res=max<unsigned int>(res,sum-currsum);
        }
        return res;
        
    }
};
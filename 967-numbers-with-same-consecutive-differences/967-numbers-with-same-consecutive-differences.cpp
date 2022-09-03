class Solution {
public:
    void helper(int n,int k,int i,vector<int> &ans)
    {
       if(n==0) 
       {
           ans.push_back(i);
           return;
       }
        
        if((i%10 + k)<=9)
            {cout<<i<<" ";helper(n-1,k,(i*10+(k+i%10)),ans);}
        if(k!=0 && (i%10-k)>=0)
            {cout<<i<<" ";helper(n-1,k,(i*10+(i%10-k)),ans);}
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=9;i++)
            helper(n-1,k,i,ans);
     
        return ans;
    }
};
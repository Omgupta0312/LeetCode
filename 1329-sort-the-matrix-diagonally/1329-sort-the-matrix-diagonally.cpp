class Solution {
public:
    void helper(vector<vector<int>>& mat,int r,int c,int &R,int &C,vector<vector<int>> &ans)
    {
        int i = r, cs = c;
        priority_queue<int,vector<int>,greater<int>> pq;
        while(i<R){
            pq.push(mat[i++][cs++]);
            if(i==R || cs==C)
                break;  
        }
        cs=c;i=r;
        while(i<R){ 
            ans[i++][cs++]=pq.top();
            pq.pop();
            if(pq.empty() || i==R || cs==C) 
                break;
        }
     
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int R=mat.size(),C=mat[0].size();
        vector<vector<int>> ans(R,vector<int>(C,-1));
        for(int i=0;i<C;i++)
            helper(mat,0,i,R,C,ans);
        
        for(int i=1;i<R;i++)
            helper(mat,i,0,R,C,ans);
        
        for(auto &x:ans)
        {
            for(auto &y:x)
                cout<<y<<" ";
            cout<<endl;
        }
       
        return ans;
    }
};
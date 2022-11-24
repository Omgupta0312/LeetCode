class Solution {
public:
    bool helper(vector<vector<char>>& b, string &w , int k ,int i,int j, vector<vector<bool>>& v)
    {   
        if(i>=b.size() || i<0 || j>=b[0].size() || j<0 || v[i][j] || b[i][j]!=w[k])
            return false;
        
         if(b[i][j]==w[k] && k==w.size()-1)
            return true;
        
        // cout<<b[i][j]<<" ";
        
        v[i][j]=1;
        bool ans = helper(b,w,k+1,i,j+1,v) || helper(b,w,k+1,i,j-1,v) || helper(b,w,k+1,i+1,j,v) ||  helper(b,w,k+1,i-1,j,v);
        
        v[i][j]=0;
        return ans;
        
    }
    bool exist(vector<vector<char>>& b, string word) {
        
        
        for(int i=0;i<b.size();i++)
        {
            for(int j=0;j<b[0].size();j++)
            {
                vector<vector<bool>> v(b.size(),vector<bool>(b[0].size(),0));
                if(word[0]==b[i][j] && helper(b,word,0,i,j,v))
                    return true;
                
            }
        }
    return false;
    }
};
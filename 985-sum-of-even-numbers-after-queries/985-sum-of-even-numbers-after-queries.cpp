class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& v, vector<vector<int>>& q) {
        int sum=0;
        for(auto &x:v)
            if(x%2==0)
                sum+=x;
        
        vector<int>ans;
        for(int i=0;i<q.size();i++)
        {
            if(v[q[i][1]]%2==0)
                sum-=v[q[i][1]];
            
            v[q[i][1]] = v[q[i][1]] + q[i][0];
            if(abs(v[q[i][1]])%2==0)
            {
                sum+=v[q[i][1]];
                
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
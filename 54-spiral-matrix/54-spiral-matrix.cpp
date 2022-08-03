class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int rs=0,re=matrix.size()-1,cs=0,ce=matrix[0].size()-1;
        while(rs<=re && cs<=ce){
            for(int i=cs;i<=ce;i++)
                v.push_back(matrix[rs][i]);
            rs++;
            if(rs>re || cs>ce) return v;
            
            for(int i=rs;i<=re;i++)
                v.push_back(matrix[i][ce]);
            ce--;
            if(rs>re || cs>ce) return v;
            
            for(int i=ce;i>=cs;i--)
                v.push_back(matrix[re][i]);
            re--;
             if(rs>re || cs>ce) return v;
            
            for(int i=re;i>=rs;i--)
                v.push_back(matrix[i][cs]);
            cs++;
            if(rs>re || cs>ce) return v;
            
        }
        return v;
    }
};
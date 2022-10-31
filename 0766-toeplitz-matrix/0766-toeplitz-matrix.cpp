class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(i+j >= matrix.size())
                    break;
                
                if(matrix[i][0] != matrix[i+j][j])
                    return false;
            }
        }
        
        for(int i=1;i<matrix[0].size();i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                if(i+j >= matrix[0].size())
                    break;
                
                if(matrix[0][i] != matrix[j][i+j])
                    return false;
            }
        }
        return true;
        
    }
};
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size();
        for(int i=0;i<mat.size();i++){
            ans+=mat[i][i];
        }
        
        int i=0;
        for(int j=mat.size()-1;j>=0;j--){
            ans+=mat[i++][j];
        }
        
        if(mat.size()%2){
            ans-=mat[n/2][n/2];
        }
        return ans;
    }
};
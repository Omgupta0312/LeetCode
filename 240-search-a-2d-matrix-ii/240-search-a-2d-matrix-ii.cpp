class Solution {
public:
    bool helper(vector<int> &v,int key)
    {
        int l=0,h=v.size()-1;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(v[m]==key)
                return true;
            else if(v[m]<key)
                l=m+1;
            else
                h=m-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][0]<=target && matrix[i].back()>=target)
            {
                if(helper(matrix[i],target))
                    return true;
            }
        }
        return false;
    }
};
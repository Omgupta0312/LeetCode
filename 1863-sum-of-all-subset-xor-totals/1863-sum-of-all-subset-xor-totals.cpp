class Solution {
public:
    int helper(vector<int>& nums,int i,vector<int>&v)
    {
        if(i==nums.size())
        {
            int r=0;
            for(auto x:v)
                r^=x;
            return r;
        }
        
        v.push_back(nums[i]);
        int p=helper(nums,i+1,v);
        v.pop_back();
        int q=helper(nums,i+1,v);
        return p+q;
        
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int>v;
        return helper(nums,0,v);
    }
};
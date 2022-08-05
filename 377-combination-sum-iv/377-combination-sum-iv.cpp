class Solution {
public:
    int helper(vector<int>& nums, int target,vector<int>& v)
    {
        if(target==0)
            return v[target]=1;
        
        if(v[target]!=-1)
            return v[target];
        
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=target)
                count+=helper(nums,target-nums[i],v);
            else break;
        }
        return v[target]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> v(1000,-1);
        sort(nums.begin(),nums.end());
        return helper(nums,target,v);
    }
};
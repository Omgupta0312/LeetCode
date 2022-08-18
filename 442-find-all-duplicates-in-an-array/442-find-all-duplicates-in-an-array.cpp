class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            int t = nums[i];
            if(nums[abs(t)-1]<0)
                v.push_back(abs(nums[i]));
            else
                nums[abs(t)-1]*=-1;
        }
        return v;
    }
};
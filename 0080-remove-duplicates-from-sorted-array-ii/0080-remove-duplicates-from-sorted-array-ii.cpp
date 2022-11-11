class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size() && i<2;i++)
            v.push_back(nums[i]);
        if(nums.size()<2) {
            return nums.size();
        } 
        for(int i=2;i<nums.size();i++)
        {
            if(v[v.size()-1] !=nums[i])
                v.push_back(nums[i]);
            
            else if(v[v.size()-2] !=nums[i]){
                 v.push_back(nums[i]);
            }
            else if(v[v.size()-2] == nums[i])
                continue;
        }
        nums=v;
        return v.size();
    }
};
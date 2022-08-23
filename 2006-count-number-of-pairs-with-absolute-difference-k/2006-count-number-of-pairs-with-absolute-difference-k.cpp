class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int>m;int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i]-k)!=m.end())
                count+=m[nums[i]-k];
            
            if(k!=0 && m.find(nums[i]+k)!=m.end())
                count+=m[nums[i]+k];
            
            m[nums[i]]++;
        }
        return count;
    }
};
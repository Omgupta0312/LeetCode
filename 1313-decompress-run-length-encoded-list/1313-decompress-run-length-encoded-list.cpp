class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i+=2)
        {
            int x=nums[i],n=nums[i+1];
            while(x--!=0)
                ans.push_back(n);
        }
        return ans;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1,prev=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=prev)
            {
                prev=nums[i];
                nums[k]=prev;
                k++;
                
            }
        }
        return k;
    }
};
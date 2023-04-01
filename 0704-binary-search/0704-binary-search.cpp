class Solution {
public:
    int search(vector<int>& nums, int target) {
        int it = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(it==nums.size())return -1;
        if(nums[it]!=target) return -1;
        else return it;
    }
};
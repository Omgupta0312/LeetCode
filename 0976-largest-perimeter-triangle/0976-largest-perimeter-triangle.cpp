class Solution {
public:
    bool check(int &a,int &b,int &c)
    {
        return a+b >c && a+c >b && c+b>a;
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(check(nums[i],nums[i+1],nums[i+2]))
                return nums[i] + nums[i+1] + nums[i+2];
        }
        return 0;
    }
};
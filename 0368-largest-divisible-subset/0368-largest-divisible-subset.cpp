class Solution {
public:
//     int helper(vector<int>&v,int i,int pi){
        
//         if(i>=v.size())
//             return 0;
//         int len  = helper(v,i+1,pi);
        
//         if(pi==-1 || v[i]%v[pi]==0 || v[pi]%v[i]==0){
//             len = max(len , 1+helper(v,i+1,i));
//         }
        
//         return len;
//     }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> dp(nums.size(),1), hash(nums.size());
        int maxi=1;
        int lastIndex = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            hash[i]=i;
            for(int prev = 0 ;prev <i;prev++)
            {
                if(nums[i]%nums[prev]==0 && 1+ dp[prev] > dp[i])
                {
                    dp[i] = 1 +dp[prev];
                    hash[i]=prev;
                }
            }
            
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        
        reverse(temp.begin(),temp.end());
        return temp;
            
    }
};
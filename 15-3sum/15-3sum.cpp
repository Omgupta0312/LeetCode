class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        if(nums.size()<3) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
           if(i==0 || (i>0 && nums[i]!=nums[i-1])) {
            
           int j=i+1,k=nums.size()-1;
           while(j<k)
           {
               if(nums[i]+nums[j]+nums[k]==0)
               {
                   vector<int> v {{nums[i],nums[j],nums[k]}};
                   ans.push_back(v);
                  
                   while(j<k && nums[j]==nums[j+1])j++;
                   while(k>j && nums[k]==nums[k-1])k--;
                   
                   j++;
                   k--;
               }
               else if(nums[i]+nums[j]+nums[k]>0)
                   k--;
               else
                   j++;
               
           }
        }
        }
        return ans;
    }
};
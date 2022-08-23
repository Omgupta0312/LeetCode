class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        vector<vector<int>>ans;
        long long int target = (long long int)tar;
        set<vector<int>>s;
        if(nums.size()<4)
            return ans;
        
        sort(nums.begin(),nums.end());
        
        for(int p=0;p<nums.size()-3;p++)
        {
            if(p==0 || (p>0 && nums[p]!=nums[p-1])){
            for(int i=p+1;i<nums.size()-2;i++)
            {
               if(i==p+1 || (i>0 && nums[i]!=nums[i-1])) {

               int j=i+1,k=nums.size()-1;
               while(j<k)
               {
                   long long int x = nums[p];
                   x+=nums[i];
                   x+=nums[j];
                   x+=nums[k];
                   if(x == target)
                   {
                       vector<int> v {{nums[p],nums[i],nums[j],nums[k]}};
                       sort(v.begin(),v.end());
                       s.insert(v);

                       while(j<k && nums[j]==nums[j+1])j++;
                       while(k>j && nums[k]==nums[k-1])k--;

                       j++;
                       k--;
                   }
                   else if(x>target)
                       k--;
                   else
                       j++;

               }
            }
            }
            
        }
        }
        for(auto &x:s)
            ans.push_back(x);
    return ans;
    }
};
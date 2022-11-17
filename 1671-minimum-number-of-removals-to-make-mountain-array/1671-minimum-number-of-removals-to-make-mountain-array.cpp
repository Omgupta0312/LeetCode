class Solution {
public:
//      vector<int> LISlefttoright(vector<int>&nums){
//         vector<int>dp(nums.size(),1);
//         for(int i =1;i<nums.size();i++){
//             for(int j=0;j<i;j++){
//                 if(nums[i]>nums[j] && dp[i]<dp[j]+1){
//                     dp[i]=dp[j]+1;
                   
//                 }
                    
//             }
//         }
//         return dp;
    
//     }
//     vector<int> LISrighttoleft(vector<int>&nums){
       
//         vector<int>dp(nums.size(),1);
//         for(int i=nums.size()-2;i>=0;i--){
//             for(int j=nums.size()-1;j>i;j--){
//                 if(nums[i]>nums[j] && dp[i]<dp[j]+1){
//                     dp[i]=dp[j]+1;
//                 }
//             }
//         }
//         return dp;
//     }
//     int minimumMountainRemovals(vector<int>& nums) {
//        vector<int>dp1=LISlefttoright(nums);
//         vector<int>dp2=LISrighttoleft(nums);
//         int result=-1;
//         for(int i =0;i<nums.size();i++){
          
//             if(dp1[i]==1 || dp2[i]==1) continue; 
            
//             result=max(result,dp1[i]+dp2[i]-1); 
//         }
//         return nums.size()-result;
//     }
    vector<int> LIS_L(vector<int> &nums){
        vector<int> dp(nums.size(),1);
        for(int i=0;i<nums.size();i++){
           for(int prev = 0 ;prev <i;prev++){
                if(nums[prev] < nums[i] && 1+ dp[prev] > dp[i]){
                    dp[i] = 1 +dp[prev];
                }
            }
        
        }
        return dp;
      
            
    }
    vector<int> LIS_R(vector<int> &nums){
        vector<int> dp(nums.size(),1);
        for(int i=nums.size()-1;i>=0;i--){
           for(int prev = nums.size()-1 ;prev > i;prev--){
                if(nums[prev] < nums[i] && 1+ dp[prev] > dp[i]){
                    dp[i] = 1 +dp[prev];
                }
            }
        
        }
        return dp;
      
            
    }
    
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> dp1 = LIS_L(nums);
        vector<int> dp2 = LIS_R(nums);
       
        
        int result=-1;
        for(int i =0;i<nums.size();i++){
            cout<<dp1[i]<<" "<<dp2[i]<<endl;
            if(dp1[i]==1 || dp2[i]==1) continue; 
            result=max(result,dp1[i]+dp2[i]-1); 
        }
        return nums.size()-result;
        
    }
};
const unsigned int mod=1000000007;
class Solution {
public:
//     int helper(vector<int>& arr)
//     {
//         unsigned int ans=0;
//         sort(arr.begin(),arr.end());
//         vector<int>dp(arr.size(),1);
        
//         for(int i=1;i<arr.size();i++){
//             int j=0,k=i-1;
//             while(j<=k)
//             {
//                 long long int x =arr[j]*arr[k];
//                 if(x==(long long)arr[i])
//                 {
//                     if(j==k) 
//                         dp[i] = (dp[i]%mod + (dp[j]%mod * dp[j]%mod) %mod ) %mod;
//                     else
//                         dp[i]=(dp[i]%mod + ((dp[j]%mod * dp[k]%mod)%mod *2)%mod)%mod;
//                     j++;
//                     k--;
//                 }
                
//                 else if(x<(long long)arr[i]){
//                     j++;
//                 }
//                 else
//                     k--;
//             }
          
//             }
            
//          for(auto &x:dp){
//             ans = (ans%mod + x%mod)%mod;
//         }
//          return ans%mod;   
//     }
       
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        int ans=0;
        sort(arr.begin(),arr.end());
        vector<long long>dp(arr.size(),1);
        
        for(int i=1;i<arr.size();i++){
            unordered_map< unsigned int, unsigned int> mp;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0){
                    unsigned int x = arr[i]/arr[j];
                    if(x == arr[j])
                        dp[i] = (dp[i]%mod + (dp[j]%mod * dp[j]%mod) %mod ) %mod;
                    else 
                        if(mp.find(x)!=mp.end())
                           dp[i]=(dp[i]%mod + ((dp[mp[x]]%mod * dp[j]%mod)%mod *2)%mod)%mod;
                         
                }
                mp[arr[j]]=j;
            }
            
        }
        for(auto &x:dp){
            ans = (ans%mod + x%mod)%mod;
        }
        
        return ans%mod;   
        // return helper(arr);
    }
};
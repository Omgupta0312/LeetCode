class Solution {
public:
    bool helper(vector<int> &arr, int i,int t,vector<vector<int>>&dp)
{
    if(t==0) return true;
    if(i==arr.size()-1) return t==arr[i];
    
    if(dp[i][t]!=-1) return dp[i][t];
    bool take = false;
    if(t>=arr[i])
        take = helper(arr,i+1,t-arr[i],dp);
    return dp[i][t] = take || helper(arr,i+1,t,dp);
}
    bool canPartition(vector<int>& arr) {
    int sum=0,n=arr.size();
    for(auto &x:arr)
        sum+=x;
    if(sum%2==1) return false;
    
    int target=sum/2;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return helper(arr,0,target,dp);
    }
};
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	const int mod = 1e9 + 7;
	long long helper(vector<int> &arr,int n,int tar, vector<vector<long long>>&dp)
    {
    
        if (n < 0) return tar==0;
        
        if(dp[n][tar]!=-1)
             return dp[n][tar]%mod;
             
        long long take=0;
        if(tar>=arr[n])
            take = helper(arr,n-1,tar-arr[n],dp)%mod;
            
        return dp[n][tar]= (1ll*take%mod + 1ll*helper(arr,n-1,tar,dp)%mod)%mod;
        
    }
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<int> v;
        for(int i =0;i<n;i++){
            v.push_back(arr[i]);
        }
        
        vector<vector<long long>> dp(n,vector<long long>(sum+1,-1));
        return helper(v,n-1,sum,dp)%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
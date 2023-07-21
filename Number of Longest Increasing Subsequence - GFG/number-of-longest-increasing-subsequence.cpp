//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&nums) {
        // Code here
        vector<int> lis(nums.size(),1);
        vector<int> cnt(nums.size(),1);

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    int l = lis[j] + 1;
                    if(l > lis[i]){
                        lis[i] = l;
                        cnt[i] = cnt[j];
                    }else if(l ==  lis[i]){
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        int m = -1;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(lis[i]>m){
                m = lis[i];
                ans = cnt[i];
            }else if(lis[i] == m){
                ans += cnt[i];
            }
        }
        return ans;

    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
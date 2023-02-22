//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int a[], int N, int days) {
        // code here
        int M=days;
        if(N<M) return -1;
        int sum=a[0];
        int maxi=a[0];
        for(int i=1;i<N;i++){
            sum+=a[i];
            maxi=max(maxi,a[i]);
        }
        
        int low = maxi;
        int high = sum;
        int ans = 0;
        
        while(low<=high){
            // cout<<low<<" "<<high<<endl;
            int mid = low + (high - low)/2;
            int cnt = 1;
            int currSum=0;
            for(int i=0;i<N;i++){
                if(currSum+a[i]>mid){
                    currSum=0;
                    cnt++;
                }
                currSum+=a[i];
                
                if(cnt>M){
                    low=mid+1;
                    break;
                }
            }
            if(cnt<=M){
                high = mid-1;
                ans = mid;
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends
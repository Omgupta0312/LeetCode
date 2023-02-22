//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int a[], int N, int M) 
    {
        //code here
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
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
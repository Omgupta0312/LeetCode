//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
        // Your code here
        long long ans = 0;
        stack<long long> s;

        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n || heights[s.top()]>=heights[i])){
                long long height = heights[s.top()];
                s.pop();
                long long width;
                if(s.empty()) width = i;
                else width = i - s.top()-1;

                ans=max<long long>(ans,height*width);
            }
            s.push(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
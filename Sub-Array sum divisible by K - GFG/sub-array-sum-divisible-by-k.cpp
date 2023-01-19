//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long subCount(long long nums[], int n, long long k)
	{
	    // Your code goes here
	    unordered_map<long,long> m;
        m[0]=1;
        long long sum=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            long long x = sum%k;
            if(x<0) x+=k;

            if(m.find(x)!=m.end()){
                ans+=m[x];
                m[x]++;
            }else{
                m[x]=1;
            }
        }
        return ans;
	}



};


//{ Driver Code Starts.

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
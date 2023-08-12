//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int nums[], int N){
	    //code
	    int l=0,h=N-1;
        while(l<=h){
            int m = (h-l)/2 + l;
            
            if(m-1>=0 && nums[m] == nums[m-1]){
                if(m%2==0) h = m-2;
                else l = m+1;
            }else if(m+1 < N && nums[m] == nums[m+1]){
                if(m%2) h = m-1;
                else l = m+2;
            }else{
                return nums[m];
            }
        }
        return nums[l];
	    
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxP2(int n){
        int x = 0;
        while((1<<x) <= n){
            x++;
        }
        return x-1;
    }
    int helper(int n){
        if(n==0) return 0;
        
        int x = maxP2(n);
        int bits_till_2Pow_X = x*(1<<(x-1));
        int rem = (n - (1<<x) + 1);
        int leftN = (n-(1<<x));
        return bits_till_2Pow_X + rem + helper(leftN);
        
    }
    int countBits(int n){
        return helper(n);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.countBits(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
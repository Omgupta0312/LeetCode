//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> getnsl(vector<int> &arr,int n){
        vector<int> v;
        stack<int> s;
        for(int i=0;i<n;i++){
            if(s.empty()) v.push_back(-1);
            else{
                while(s.empty()== false && arr[s.top()] >= arr[i]){
                    s.pop();
                }
                if(s.empty()) v.push_back(-1);
                else{
                    v.push_back(s.top());
                }
            }

            s.push(i);
        }
        return v;
    }

    vector<int> getnsr(vector<int> &arr,int n){
        vector<int> v(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            if(s.empty()) v[i]=n;
            else{
                while(s.empty()== false && arr[s.top()] > arr[i]){
                    s.pop();
                }
                if(s.empty()) v[i]=n;
                else{
                    v[i] = s.top();
                }
            }

            s.push(i);
        }
        return v;
    }

  
    int sumSubarrayMins(int N, vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> nsl = getnsl(arr,n);
        vector<int> nsr = getnsr(arr,n);

        long long sum = 0;
        int mod = 1e9+7;
        
        for(int i=0;i<n;i++){
            long long ls = i - nsl[i];
            long long rs = nsr[i] - i;

            sum = (sum%mod + ((ls * rs)%mod * arr[i])%mod)%mod;
        }

        return sum%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
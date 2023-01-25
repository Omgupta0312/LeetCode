//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        stack<int> s;

        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n || heights[s.top()]>=heights[i])){
                int height = heights[s.top()];
                s.pop();
                int width;
                if(s.empty()) width = i;
                else width = i - s.top()-1;

                ans=max(ans,height*width);
            }
            s.push(i);
        }
        return ans;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int> dp(m,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==0){
                    dp[j]=0;
                }else
                    dp[j]+=1;
            }

            ans = max(ans,largestRectangleArea(dp));

        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends
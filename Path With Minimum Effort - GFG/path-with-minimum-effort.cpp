//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n=heights.size();
        int m=heights[0].size();
        
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        pq.push({0,{0,0}});
        int dr[4]={-1,0,0,1};
        int dc[4]={0,-1,1,0};
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int r = it.second.first;
            int c = it.second.second;
            int diff = it.first;
            
            if(r==n-1 && c==m-1) return diff;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int jump = abs(heights[r][c]-heights[nr][nc]);
                    int newEffort = max(jump,diff);
                    if(newEffort < dis[nr][nc]){
                        pq.push({newEffort,{nr,nc}});
                        dis[nr][nc]=newEffort;
                    }
                    // if(jump > diff && jump < dis[nr][nc]){
                    //     pq.push({jump,{nr,nc}});
                    //     dis[nr][nc]=jump;
                        
                    // }else if(jump < diff && diff < dis[nr][nc]){
                    //     pq.push({diff,{nr,nc}});
                    //     dis[nr][nc]=diff;
                    // }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
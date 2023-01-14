//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> final) {
        // code here
        if(source == final) return 0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{source.first,source.second}});
        
        vector<vector<int>> dis(grid.size(),vector<int>(grid[0].size(),1e9));
        dis[source.first][source.second]=0;
        int dr[4]={-1,0,0,1};
        int dc[4]={0,-1,1,0};
      
        while(q.empty()==false){
            
            int l = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            // cout<<l<<" "<<r<<" "<<c<<endl;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc] && l+1 < dis[nr][nc]){
                    dis[nr][nc] = 1+l;
                  
                    if(nr==final.first && nc==final.second){
                        return l+1;
                    }
                    q.push({dis[nr][nc],{nr,nc}});
                }
            }
        }
       
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
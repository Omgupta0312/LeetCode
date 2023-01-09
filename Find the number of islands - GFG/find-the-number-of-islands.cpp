//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void helper(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>& vis){
        
        for(int dr=-1;dr<=1;dr++){
            for(int dc=-1;dc<=1;dc++){
                int nr=i+dr;
                int nc=j+dc;
                
                if(nc==j && nr==i) continue;
                else if(nc>=0 && nc<vis[0].size() && nr>=0 && nr<vis.size() && grid[nr][nc]=='1'
                && !vis[nr][nc] ){
                    vis[nr][nc]=1;
                    helper(grid,nr,nc,vis);
                }
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),0));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    vis[i][j]=1;
                    helper(grid,i,j,vis);
                    count++;
                    
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
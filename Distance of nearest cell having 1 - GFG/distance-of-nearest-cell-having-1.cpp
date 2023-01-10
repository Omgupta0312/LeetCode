//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    
	    queue<pair<pair<int,int>,int>> q;
	    vector<vector<int>> vis (grid.size(),vector<int>(grid[0].size(),0));
	    vector<vector<int>> dis (grid.size(),vector<int>(grid[0].size(),0));
	    
	    for(int i=0;i<grid.size();i++){
	        for(int j=0;j<grid[0].size();j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                vis[i][j]==1;
	            }
	        }
	    }
	    
	    int dr[4]={-1,0,0,1};
	    int dc[4]={0,-1,1,0};
	    
	    while(q.empty()==false){
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int step = q.front().second;
	        q.pop();
	        
	        dis[r][c]=step;
	        
	        for(int x=0;x<4;x++){
	            int nr = r+dr[x];
	            int nc = c+dc[x];
	            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && !vis[nr][nc] && !grid[nr][nc]){
	                vis[nr][nc]=1;
	                q.push({{nr,nc},step+1});
	            }
	        }
	        
	        
	    }
	    return dis;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
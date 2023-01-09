//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int rd[4]={-1,0,1,0};
        int cd[4]={0,-1,0,1};
        int n= grid.size(),m=grid[0].size(),t=0,tr=0;
        int cntFresh=0,cnt=0;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                {
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }else if(grid[i][j]==1){
                    cntFresh++;
                }
            }
        }

        while(q.empty()==false){

            pair<pair<int,int>,int> x = q.front();
            q.pop();
            int t=x.second;
            int r=x.first.first;
            int c=x.first.second;

            tr=max(tr,t);
            for(int i=0;i<4;i++){
                int nr = r+rd[i];
                int nc = c+cd[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]!=2 && grid[nr][nc]==1){
                    vis[nr][nc]=2;
                    cnt++;
                    q.push({{nr,nc},t+1});
                }
            }
        }

        if(cnt!=cntFresh)
        return -1;

        return tr;

        
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
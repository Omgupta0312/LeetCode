//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int i,vector<int> a[],vector<int> &vis,vector<int> &path){
        for(auto &adjnode:a[i]){
            if(vis[adjnode]==0){
                vis[adjnode]=1;
                path[adjnode]=1;
                if(dfs(adjnode,a,vis,path))
                return true;
                else{
                    path[adjnode]=0;
                }
                
            }
            else if(vis[adjnode]==1 && path[adjnode]==0)
            {
                continue;
                // path[adjnode]=1;
                // if(dfs(adjnode,a,vis,path))
                //     return true;
                // else path[adjnode]=0;
            }
            else{
                return true; 
            }
        }
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> path(V,0);
        
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                vis[i]=1;
                path[i]=1;
                if(dfs(i,adj,vis,path)){
                    return true;
                }
                path[i]=0;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
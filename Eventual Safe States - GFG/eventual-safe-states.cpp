//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   bool dfs(int i,vector<int> a[],vector<int> &vis,vector<int> &path,vector<int> &check){
        vis[i]=1;
        path[i]=1;
        for(auto &adjnode:a[i]){
            if(vis[adjnode]==0){
                if(dfs(adjnode,a,vis,path,check))
                     return true;
            }
            else if(path[adjnode])
                return true;
          
        }
        check[i]=1;
        path[i]=0;
        return false;
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> path(V,0);
        vector<int> check(V,0);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,adj,vis,path,check);
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]){
                ans.push_back(i);
            }
        }
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
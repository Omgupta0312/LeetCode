//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>> adj(N,vector<int>(N,0));
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]][edges[i][1]]=1;
            adj[edges[i][1]][edges[i][0]]=1;
            
        }
        
        queue<pair<int,int>>q;
        vector<int> dis(N,INT_MAX);
        dis[src]=0;
        q.push({src,0});
        while(q.empty()==false){
            int v = q.front().first;
            int d = q.front().second;
            q.pop();
            
            for(int i=0;i<adj[v].size();i++){
                if(adj[v][i])
                {
                   if(dis[i]>d+1){
                       dis[i]=d+1;
                       q.push({i,dis[i]});
                   }
                }
            }
        }
        for(auto &x:dis){
            if(x==INT_MAX) x=-1;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
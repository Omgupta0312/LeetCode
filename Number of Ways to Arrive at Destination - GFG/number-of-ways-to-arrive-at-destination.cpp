//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<int,int>> adj[n];
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        vector<int> dis(n,1e9) , way(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
        // pq stores {dis,node}
        pq.push({0,0});
        dis[0]=0;
        way[0]=1;
        
        long long int mod = 1e9 + 7;
        while(pq.empty()==false){
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            // cout<<d<<" "<<node<<endl;

            for(auto &adjNode : adj[node]){
                int nNode = adjNode.first;
                int dN = adjNode.second;

                if(d + dN == dis[nNode]){
                    way[nNode] = (way[nNode]%mod + way[node]%mod)%mod;
                }
                else if(d + dN < dis[nNode]){
                    way[nNode]=way[node];
                    dis[nNode] = d + dN;
                    pq.push({dis[nNode],nNode});
                }
                
            }
        }
        // for(auto &x:way) cout<<x<<" ";
        return way[n-1]%mod;
    
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends
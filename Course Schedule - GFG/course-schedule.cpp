//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> arr) 
    {
        vector<vector<int>> adj(n,vector<int>(0,0));
        vector<int> incoming(n,0),ans;

        for(auto &x:arr){
            adj[x[1]].push_back(x[0]);
            incoming[x[0]]++;
        }

        queue<int> q;
        for(int i=0;i<incoming.size();i++){
            if(incoming[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int front = q.front();
            q.pop();

            ans.push_back(front);
            for(auto &adjN : adj[front]){
                if(incoming[adjN]==0){
                    return {};
                }
                incoming[adjN]--;
                if(incoming[adjN]==0)
                {
                    q.push(adjN);
                }
            }

        }
        for(auto &x:incoming){
            if(x!=0) return {};
        }
        return ans;

       

        
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
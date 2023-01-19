//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    private:
        void dfs(int i,vector<int> &vis,stack<int> &s,vector<int> adj[]){
            vis[i]=1;
            for(auto it:adj[i]){
                if(vis[it]==false){
                    dfs(it,vis,s,adj);
                }
            }
            s.push(i);
        }
        
        void dfsN(int i,vector<int> &vis,vector<int> adjT[]){
            vis[i]=1;
            for(auto it:adjT[i]){
                if(vis[it]==false){
                    dfsN(it,vis,adjT);
                }
            }
        }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        
        int ans=0;
        //code here
        // step 1 Used stack to see finishing time
        vector<int> vis(V,0);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,s,adj);
            }
        }
        
        //step 2 reverse all the node edges;
        vector<int> adjT[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto &it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        // step 3 take top element in do dfs to find strongly connected comp.
        while(s.empty()==false){
            int i = s.top();
            s.pop();
            if(!vis[i]){
                dfsN(i,vis,adjT);
                ans++;
            }
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
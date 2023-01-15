//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
    
        vector<vector<int>> adj(n,vector<int>(n,0));
        for(auto &x:flights){
            adj[x[0]][x[1]]=x[2];
        }
       
        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        vector<int> dis(n,1e9);
        dis[src]=0;
        pq.push({0,{src,0}});
        
        while(!pq.empty()){
            int step = pq.top().first;
            int currDis = pq.top().second.second;
            int node = pq.top().second.first;
            
            // cout<<step<<" "<<node<<endl;
            pq.pop();
            
            if(step==k+1 && node !=dst) continue;
            for(int i=0;i<n;i++){
                int w = adj[node][i];
                if(w && currDis+w<dis[i]){
                    dis[i]=currDis+w;
                    pq.push({step+1,{i,dis[i]}});
                    
                }
                
            }
                
        }
        // for(auto &x:dis) cout<<x<<" ";
        if(dis[dst]==1e9) return -1;
        return dis[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
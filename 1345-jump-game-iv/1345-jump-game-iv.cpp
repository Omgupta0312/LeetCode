class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size()==1) return 0;
        
        vector<int> vis(arr.size(),0);
        unordered_map<int,set<int>> m;
        for(auto i=0;i<arr.size();i++){
            m[arr[i]].insert(i);
        }
        
        
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0]=1;
        int ans = 1e9;
        while(q.empty()==false){
            int node = q.front().second;
            int steps = q.front().first;
            q.pop();
            
            if(node == arr.size()-1) ans = min(ans,steps);
            
            int nodeV = arr[node];
            
            for(auto it:m[nodeV]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({steps+1,it});
                }
            }

            if(node-1 >= 0 && vis[node-1]==0){
                vis[node-1]=1;
                q.push({steps+1,node-1});
            }
            if(node+1 < arr.size() && vis[node+1]==0){
                vis[node+1]=1;
                q.push({steps+1,node+1});
            }
            
            m[arr[node]].clear();
        
        }
        return ans;
    }
};
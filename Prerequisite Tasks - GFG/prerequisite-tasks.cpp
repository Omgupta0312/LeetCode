//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& arr) {
	    // Code here
	    vector<vector<int>> adj(n,vector<int>(0,0));
        vector<int> incoming(n,0);

        for(auto &x:arr){
            adj[x.second].push_back(x.first);
            incoming[x.first]++;
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

            for(auto &adjN : adj[front]){
                // if(incoming[adjN]==0){
                //     return {};
                // }
                incoming[adjN]--;
                if(incoming[adjN]==0)
                {
                    q.push(adjN);
                }
            }

        }
        for(auto &x:incoming){
            if(x!=0) return false;
        }
        return true;
    }
	
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
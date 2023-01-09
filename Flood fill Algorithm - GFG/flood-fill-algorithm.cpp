//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<int> dr;
    vector<int> dc;
     int c;
    int inic;
    Solution(){
        dr={-1,0,1,0};
        dc={0,-1,0,1};
    }

    void helper(vector<vector<int>>& image ,int i ,int j){
        if(image[i][j]==inic){
            image[i][j]=c;
            for(int x=0;x<4;x++){
                int nr=i+dr[x];
                int nc=j+dc[x];
                // for(auto &m:image){
                //     for(auto &n:m){
                //         cout<<n<<" ";

                //     }
                //     cout<<endl;
                // }
                if(nr>=0 && nr<image.size() && nc>=0 && nc<image[0].size())
                    helper(image,nr,nc);
            }

        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Code here 
        vector<vector<int>> ans=image;
        c=color;
        inic=image[sr][sc];
        if(inic != c)
            helper(ans,sr,sc);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
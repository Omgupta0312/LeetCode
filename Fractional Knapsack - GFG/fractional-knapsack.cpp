//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    bool static myComp(pair<double,Item> &a , pair<double,Item> &b){
        return a.first > b.first;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,Item>> v;
        for(int i=0;i<n;i++){
            double f = ((1.0 * arr[i].value) / arr[i].weight);
            v.push_back({f,arr[i]});
        }
        
        
        sort(v.begin(),v.end(),myComp);
        double ans = 0;
        int i=0;
        while(W>=0 && i<n){
            if(v[i].second.weight <= W){
                ans += 1.0 * v[i].second.value;
                W = W - v[i].second.weight;
            }else{
                ans += 1.0 * v[i].first * W;
                W = 0;
                break;
            }
            i++;
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
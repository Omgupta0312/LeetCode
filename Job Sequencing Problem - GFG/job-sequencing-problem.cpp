//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    bool static myComp(Job &a, Job &b){
        if(a.profit > b.profit) return true;
        else if(a.profit < b.profit) return false;
        else if(a.dead > b.dead) return true;
        else return false;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,myComp);
        int maxDuration = 0;
        for(int i=0;i<n;i++){
            maxDuration = max(maxDuration,arr[i].dead);
        }
        int ans = 0;
        int cnt = 0;
        vector<int> jobList(maxDuration,-1);
        
        for(int i=0;i<n;i++){
            for(int j = arr[i].dead-1 ;j>=0;j-- ){
                if(jobList[j] == -1){
                    ans += arr[i].profit;
                    jobList[j]=arr[i].id;
                    cnt++;
                    break;
                }
            }
        }
        
        return {cnt,ans};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
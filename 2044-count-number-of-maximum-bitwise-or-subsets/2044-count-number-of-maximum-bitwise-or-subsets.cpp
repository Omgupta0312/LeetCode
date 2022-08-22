unordered_map<int,int> mp;
class Solution {
public:
    void helper(vector<int> &arr,int i,int &res,int &maxor)
    {
        if(i==arr.size())
        { 
           maxor=max(maxor,res);
           mp[res]++;
            return;
        }
        
        int x = res | arr[i];
        helper(arr,i+1,x,maxor);
        helper(arr,i+1,res,maxor);

    }
  
    int countMaxOrSubsets(vector<int>& nums) {
        int res=0,maxor=0;
        helper(nums,0,res,maxor);
        // for(auto x:mp)
        //     cout<<x.first<<" "<<x.second<<endl;
        int ans = mp[maxor];
        mp.clear();
        return ans;
    }
};
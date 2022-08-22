class Solution {
public:
    void helper(vector<int> &arr,int i,vector<int>&v, set<vector<int>>&ans)
    {
        if(i==arr.size())
        { 
           ans.insert(v);
           return;
        }
        
        v.push_back(arr[i]);
        helper(arr,i+1,v,ans);
        v.pop_back();
        helper(arr,i+1,v,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int>v;
        helper(nums,0,v,ans);
        vector<vector<int>> res;
        
        for(auto &x:ans)
            res.push_back(x);
        return res;
    }
};
class Solution {
public:
    void helper(vector<int> &cand,int i,int t,vector<int> &v,vector<vector<int>> &ans)
    {
        if(i<0)
        {
            if(t==0)
                ans.push_back(v);
              
            return;
        }
        if(t==0){
            ans.push_back(v);
            return;
        }
        
        helper(cand,i-1,t,v,ans);
        
        if(cand[i]<=t){
            v.push_back(cand[i]);
            helper(cand,i,t-cand[i],v,ans);
            v.pop_back();
        }
            
            
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>v;
        helper(candidates,candidates.size()-1,target,v,ans);
       
        return ans;
    }
};
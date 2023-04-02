class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        vector<int>::iterator low1;
        vector<int> ans;
        sort(p.begin(),p.end());
        for(int i=0;i<s.size();i++){
            long long k=0;
            if(success%s[i]==0)
             k = ceil(success/s[i]);
            else
             k = ceil(success/s[i])+1;
             low1 =lower_bound(p.begin(), p.end(), k);
            int t=low1 - p.begin();
            ans.push_back(p.size()-t);
        }
        return ans;
    }
};
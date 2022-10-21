class Solution {
public:
    static const bool mycomp(const pair<int,string>&a ,const pair<int,string>&b)
    {
        if(a.first==b.first) return a.second<b.second;
        return a.first > b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(auto &x:words)
            m[x]++;
        vector<pair<int,string>> v;
        for(auto &x:m)
            v.push_back({x.second,x.first});
        
        sort(v.begin(),v.end(),mycomp);
        
        vector<string> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
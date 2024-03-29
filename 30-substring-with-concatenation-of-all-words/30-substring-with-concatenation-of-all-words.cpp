class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int x = words[0].size();
        int sw = x * words.size();
        unordered_map<string,int> mp2;
    
        for(int i=0;i<s.size()-sw+1;i++){
            string temp=s.substr(i,sw);
            if(mp2.find(temp)!=mp2.end()) {
                ans.push_back(i);
                continue;
            }
            unordered_map<string,int> mp1;
            for(int i=0;i<words.size();i++)
                mp1[words[i]]++;
            
            int count=0;
            for(int j=i;j-i<=sw;j+=x){
                string t=s.substr(j,x);
                if(mp1.find(t)!=mp1.end() && mp1[t]>0){
                     mp1[t]--;
                     count++;
                }
                
                else
                    break;
                
            }
            if(count==words.size()){
                ans.push_back(i);
                mp2[temp]++;
            }
           
        }
        
        return ans;
            
    }
};
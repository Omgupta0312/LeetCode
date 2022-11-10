class Solution {
public:
    string removeStars(string str) {
        stack<char>s;
        for(int i=0;i<str.size();i++){
            if(!s.empty() && str[i]=='*')
            {
                 s.pop();
            }
            else{
                s.push(str[i]);
            }
        }
        string ans="";
        while(!s.empty()){
            char x=s.top();
            ans+=x;
            s.pop();
            
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    string removeDuplicates(string str) {
        stack<char>s;
        for(int i=0;i<str.size();i++){
            if(!s.empty() && s.top()==str[i])
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
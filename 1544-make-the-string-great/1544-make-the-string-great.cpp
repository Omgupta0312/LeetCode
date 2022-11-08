class Solution {
public:
    bool check(char &a,char &b){
        
        if((a-'a' == b-'A' && 'z'-a == 'Z'- b) || (a-'A' == b-'a' && 'Z'-a == 'z'- b)){
            return true;
        }
        return false;
    }
    string makeGood(string str) {
        stack<char> s;
        s.push(str[0]);
        for(int i=1;i<str.size();i++){
            if(!s.empty() && check(s.top(),str[i]))
            {
                s.pop();
                
            }else{
                s.push(str[i]);
            }
        }
        
        string ans="";
        while(!s.empty()){
            char x= s.top();
            s.pop();
            ans+=x;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
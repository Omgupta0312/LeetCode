class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ans;
        for(int i=0;i<chars.size();i++)
        {
            int j=i+1;
            while(j<chars.size() && chars[i]==chars[j])
                j++;
            
            if(j==i+1)
                ans.push_back(chars[i]);
            else{
                ans.push_back(chars[i]);
                string n =  to_string(j-i);
                for(auto &x:n)
                    ans.push_back(x);
                i=j-1;
            }
        }
        chars=ans;
        return ans.size();
    }
};
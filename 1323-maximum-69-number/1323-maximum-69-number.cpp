class Solution {
public:
    int maximum69Number (int num) {
        string s= to_string(num);int f6=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='6')
            {
                f6=i;break;
                
            }
        }
        if(f6!=-1)
         s[f6]='9';
        return stoi(s);
    }
};
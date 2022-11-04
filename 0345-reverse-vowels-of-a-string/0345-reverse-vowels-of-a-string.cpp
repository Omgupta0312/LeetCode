class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char,bool> m;
        m['a']=1;m['e']=1;m['i']=1;m['o']=1;m['u']=1;
        m['A']=1;m['E']=1;m['I']=1;m['O']=1;m['U']=1;
        
        int i=0,j=s.size()-1;
        while(i<=j){
            if(m.find(s[i])!=m.end() && m.find(s[j])!=m.end())
            {
                swap(s[i],s[j]);
                i++;j--;
            }
            else if(m.find(s[i])==m.end() && m.find(s[j])!=m.end())
                i++;
            else if(m.find(s[i])!=m.end() && m.find(s[j])==m.end())
                j--;
            else {
                i++;j--;
            }
        }
        return s;
    }
};
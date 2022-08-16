class Solution {
public:
    int strStr(string h, string n) {
        if(h.size()<n.size()) return -1;

        for(int i=0;i<h.size()-n.size()+1;i++)
        {
            string temp=h.substr(i,n.size());
            if(temp==n)
                return i;
            
        }
        return -1;
    }
};
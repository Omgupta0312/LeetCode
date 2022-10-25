class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        int i=0,j=0,m=0,n=0;
        while(i<w1.size() && j<w2.size()){
            if(w1[i][m]==w2[j][n])
            {
                if(m<w1[i].size() && n<w2[j].size())
                {
                    m++;n++;
                }
    
                if(m==w1[i].size()){
                    m=0;i++;
                }
                if(n==w2[j].size()){
                    n=0;j++;
            
                }
            }
            else return false;
        }
        if((i<w1.size() && j>=w2.size()) || (i>=w1.size() && j<w2.size()))
            return false;
      
        return true;
    }
};
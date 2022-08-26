class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if(n==1 || n==4 || n==8) return true;
        string s = to_string(n);
        sort(s.begin(),s.end());
        do{
            cout<<s<<" ";
            int i=0;
            for(i=0;i<s.size();i++)
                if(s[i]!='0') break;
            
            if(i==0){
                int x = stoi(s.substr(i));
                if(x>0 && __builtin_popcount(x)==1)
                  return true;
            }
        }while(next_permutation(s.begin(),s.end()));
        return false;
                
    }
};
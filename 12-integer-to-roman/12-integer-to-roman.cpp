class Solution {
public:
    string intToRoman(int num) {
        string s = to_string(num);
        string ans="";
        int e=pow(10,s.size()-1);
        for(int i=0;i<s.size();i++)
        {
            
            int n = (s[i]-48);
            if(e==1000)
            {
                while(n>0)
                {
                    ans+='M';
                    n--;
                }
                    
            }
            else if(e==100)
            {
                if(n==9) ans+="CM";
                else if(n==4) ans+="CD";
                else if(n<5)
                {
                    while(n-->0)
                        ans+='C';
                }
                else if(n>5)
                {
                    ans+='D';
                    while(n-- !=5)
                        ans+='C';
                }
                else ans+='D';
            }
            else if(e==10)
            {
                if(n==9) ans+="XC";
                else if(n==4) ans+="XL";
                else if(n<5)
                {
                    while(n-- > 0)
                      ans+='X';
                }
                else if(n>5)
                {
                    
                    ans+='L';
                    while(n-- !=5)
                        ans+='X';
                       
                }
                else ans+='L';
            }
            else{
                if(n==9) ans+="IX";
                else if(n==4) ans+="IV";
                else if(n<5)
                {
                    while(n-->0)
                        ans+='I';
                }
                else if(n>5)
                {
                    ans+='V';
                    while(n-- !=5)
                        ans+='I';
                    
                }
                else
                    ans+='V';
            }
            
            e/=10;
                
            
        }
        return ans;
    }
};
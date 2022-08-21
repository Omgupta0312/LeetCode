class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1,j=b.size()-1;
        string ans="";
        char c='0';
        while(i>=0 && j>=0)
        {
           if(a[i]=='0' && b[j]=='0')
           {
               ans+=c;
               c='0';
           }
            else if(a[i]=='0' && b[j]=='1')
            {
                
                if(c=='0')
                {
                    ans+='1';
                    c='0';
                }
                else
                {
                    ans+='0';
                    c='1';
                }
            
                
            }
            else if(a[i]=='1' && b[j]=='0')
            {
               
                if(c=='0')
                {
                    ans+='1';
                    c='0';
                }
                else
                    {ans+='0';
                    c='1';}
            }
            else if(a[i]=='1' && b[j]=='1')
            {
               
                if(c=='0')
                    ans+='0';
                else
                    ans+='1';
                 
                c='1';
                 
            }
            i--,j--;
        }
        while(j>=0)
        {
            if(b[j]=='0' && c=='0')
            {
                ans+='0';
                c='0';
            }
            else if(b[j]=='0' && c=='1')
            {
                ans+='1';
                c='0';
            }
            else if(b[j]=='1' && c=='0')
            {
                ans+='1';
                c='0';
            }
            else {
                ans+='0';
                c='1';
            }
            j--;
        }
        while(i>=0)
        {
            if(a[i]=='0' && c=='0')
            {
                ans+='0';
                c='0';
            }
            else if(a[i]=='0' && c=='1')
            {
                ans+='1';
                c='0';
            }
            else if(a[i]=='1' && c=='0')
            {
                ans+='1';
                c='0';
            }
            else {
                ans+='0';
                c='1';
            }
            i--;
        }
        if(c=='1')
            ans+='1';
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    bool isPalindrome(string s) {
         int i=0,j=s.size()-1;
    while(i<=j)
    {
        if(('A'<=s[i] && s[i]<='Z' ) || ('a'<=s[i] && s[i]<='z') || ('0'<=s[i] && '9'>=s[i])){
           if(('A'<=s[j] && s[j]<='Z' ) || ('a'<=s[j] && s[j]<='z') || ('0'<=s[j] && '9'>=s[j])){
               if('A'<=s[i] && s[i]<='Z')
                   s[i] = s[i]+32;
               
               if(('A'<=s[j] && s[j]<='Z' ))
                   s[j] = s[j]+32;
               
               if(s[i]!=s[j])
                   return false;
               
               i++;
               j--;
           }
            else{
                j--;
            }
            
        }
        else 
        {
            i++;
        }
    }
    return true;
    }
};
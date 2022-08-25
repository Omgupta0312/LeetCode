#include <string>
class Solution {
public:
    int prec(char&c)
    {
       if(c=='/' || c=='*') return 2;
       else return 1;
    }
    int postToEval(string &s)
    {
       stack<int>st;
       for(int i=0;i<s.size();i++)
       {
           if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
           {
               int op1 = st.top();
               st.pop();
               int op2 = st.top();
               st.pop();
               
               switch(s[i])
               {
                   case '+':
                       st.push(op1+op2);
                       break;
                       
                   case '-':
                       st.push(op2-op1);
                       break;
                       
                   case '*':
                       st.push(op2*op1);
                       break;
                   
                   case '/':
                       st.push(op2/op1);
                       break;
               }
           }
           else {
               int j=i+1;string t="";
               while(i<s.size())
               {
                   if(s[i]=='('){
                       i++;
                   }
                   else if(s[i]==')') 
                       break;
                   
                   else{
                       t+=s[i];
                       i++;
                   }
                   
               }
               st.push(stoi(t));
           }
       }
        return st.top();
        
    }
    string helper(string &s)
    {
        stack<char>st;
        string res="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ') continue;
            else if(s[i]=='(') st.push('(');
            else if(s[i]==')'){
                while(st.empty()==false && st.top()!=')')
                {
                  res+= st.top();
                  st.pop();
                }
                if(st.empty()!=false && st.top()==')')
                   st.pop();
            
            }
            else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                while(st.empty()==false && prec(s[i])<=prec(st.top()))
                {
                    res += st.top();
                    st.pop();
                }
                st.push(s[i]);
            
            }
            else{
                string t="";
                int j=i;
                while(j<s.size() && s[j]>='0' && s[j]<='9')
                    t+=s[j++];

                if(j!=i)
                    i=j-1;
                    
                res+='('+t+')';    
            }
            
            
        }
         while (!st.empty()) {
        res += st.top();
        st.pop();
    }
        return res;
    }
    int calculate(string s) {
        string h1 = helper(s);
        cout<<h1<<endl;
        return postToEval(h1);
    }
};
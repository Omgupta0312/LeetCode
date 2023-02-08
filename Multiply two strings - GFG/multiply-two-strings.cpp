//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string num1, string num2) {
       //Your code here
       string ans="";
        if(num1=="0" || num2=="0") return ans+='0';

        vector<int> res (num1.size()+num2.size(),0);
        int k=res.size()-1,cnt=0;
        bool neg = false;
        if(num1[0]=='-' || num2[0]=='-') neg = true;
        if(num1[0]=='-' && num2[0]=='-') neg = false;
        
        for(int i=num1.size()-1;i>=0 && num1[i]!='-';i--){
            int carry=0;
            for(int j=num2.size()-1;j>=0 && num2[j]!='-';j--){
                int p = (num1[i]-48)*(num2[j]-48) + carry + res[k];
                carry = p/10;
                res[k--] = p%10;
            }
            res[k]+=carry;
            carry=0;
            cnt++;
            k=res.size()-1-cnt;
        }

        // for(auto &x:res){
        //     cout<<x<<" ";
        // }
        int i=0;
        while(i<res.size() && res[i]==0){
            i++;
        }
        
        if(neg) ans+='-';
        while(i<res.size()){
            ans+= (res[i++]+'0');
        }
        return ans;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends
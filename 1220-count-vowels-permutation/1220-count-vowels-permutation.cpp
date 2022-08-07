const unsigned int m = 1000000007;
class Solution {
public:
    int countVowelPermutation(int n) {
       if(n==1) return 5;
        
       vector<int> v(5,1);
       int ans=0;
       while(n-1)
       {
          vector<int> temp(5,0);
          for(int i=0;i<5;i++)
              temp[i]=v[i];
          
          v[4]=temp[0]%m;
          v[3]=(temp[2]%m+temp[4]%m)%m;
          v[2]=(temp[0]%m+temp[1]%m+temp[3]%m+temp[4]%m)%m;
          v[1]=(temp[0]%m+temp[2]%m)%m;
          v[0]=(temp[1]%m);
          n--;
          
          if(n-1==0)
          {
              for(auto &x:v)
              {
                  ans+=x%m;
                  ans%=m;
              }
          }
          
       }
       return ans%m;
    }
};
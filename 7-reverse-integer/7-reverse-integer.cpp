class Solution {
public:
    int reverse(int x) {
        const int max_limit=INT_MAX;
    
    long long int ans=0;
    
    int k=abs(x);
    
    while(k>0){
        
        ans = ans*10 + (k%10);
        k /= 10;
        
    }
    
    if(ans > max_limit)
        return 0;
    
    if(x<0)
        return (-1)*ans;
    else
        return ans;

    }
};
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0)
            return false;
        for(int i=0;i<n;i++)
        {
            long long int x = pow(4,i);
            if(x==n)
                return true;
            if(x>n)
                return false;
                
        }
        return false;
    }
};
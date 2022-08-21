class Solution {
public:
    int mySqrt(int x) {
        if(x<1) return 0;
        long long int i=1;
        while(1){
            if(i*i>x)
                return i-1;
            i++;
        }
        return 1;
        
        
    }
};
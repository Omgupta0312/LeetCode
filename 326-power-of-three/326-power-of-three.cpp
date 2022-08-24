class Solution {
public:
    bool isPowerOfThree(int n) {
         return n>0 && pow (3,(int)round((log(n) /log(3)))) == n;
    }
};
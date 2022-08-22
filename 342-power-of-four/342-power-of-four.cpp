// Here, instead of using the for loop/recursion, I will use some popular built in functions of GCC:
// __builtin_popcount(x): Return the number of ones in the binary representation of x
// __builtin_ctz(x): Return the number of trailing zeroes in x.
// Let's see how we can apply the above function into this problem:
// Suppose that x is in the form 4^k
// Then we can change x to 2^(2 * k)
// It is well known in bit manipulation that 2^(2 * k) is equal to 1 << (2 * k)
// That means __builtin_popcount(x) == 1 (Since x only has one bit that got left-shifted), and __builtin_ctz(x) % 2 == 0 (Since the number of trailing zeroes are 2 * k, which is an even number).

class Solution {
public:
    bool isPowerOfFour(int n) {
        return __builtin_popcount(n) == 1 && __builtin_ctz(n) % 2 == 0;
    }

};
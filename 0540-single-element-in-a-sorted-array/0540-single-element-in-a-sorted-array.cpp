class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int Xor = 0;
        for(auto &x:nums) Xor^=x;
        return Xor;
        
    }
};
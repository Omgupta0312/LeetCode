class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int p= (minutesToTest/minutesToDie) +1;
        return (ceil)(log(buckets)/log(p));
    }
};
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c=1;
        for(int i=digits.size()-1;i>=0;i--)
        {
            int sum=digits[i]+c;
            digits[i]=sum%10;
            c=sum/10;
            cout<<c;
        }
        if(c!=0)
        {
            reverse(digits.begin(),digits.end());
            digits.push_back(c);
            reverse(digits.begin(),digits.end());
        }
        return digits;
    }
};
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
       int n=0,ans=INT_MAX;
        
        for(auto i:nums1){
            for(auto j:nums2){
                if(i==j) n=i;
                else n=min(i*10+j,j*10+i);
                ans=min(ans,n);
                
            }
        }
        return ans;
    }
};
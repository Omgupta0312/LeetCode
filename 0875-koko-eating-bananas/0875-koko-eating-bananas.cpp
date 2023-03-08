class Solution {
public:
    bool check(vector<int>&piles,int h,int m){
        int cnt = 0;
        for(auto &x:piles){
            int d=x/m;
            if(x%m!=0 || d==0) d++;
            cnt+=d;
            if(cnt>h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int hr) {
        int maxi = *max_element(piles.begin(),piles.end());
        // int mini = *min_element(piles.begin(),piles.end());
        
        int l = 1;
        int h = maxi;
        int ans = maxi;
        while(l<=h){
            int mid = (h-l)/2 + l;
            if(check(piles,hr,mid)){
                h=mid-1;
                ans=min(ans,mid);
            }else{
                l=mid+1;
            }
        }
        
        
        return ans;
    }
};
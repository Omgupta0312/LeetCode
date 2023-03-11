class Solution {
public:
    bool check(vector<int>&time,int tt,long long int m){
        long long int cnt=0;
        for(auto &x:time){
            cnt+=m/x;
            if(cnt>=tt){
                return true;
            }
        }
        return cnt>=tt;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int ans=0;
        int mt = *max_element(time.begin(),time.end());
        
        long long int low = 0;
        long long int high = 1LL*mt*totalTrips;
        
        while(low<=high){
            long long int mid = low + (high-low)/2;
            if(check(time,totalTrips,mid)){
                high = mid-1;
                ans = mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
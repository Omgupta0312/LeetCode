class Solution {
public:
    bool check(vector<int>& candies, long long k,int mid){
        long long int cnt = 0;
        for(auto &x:candies){
            cnt += floor(x/mid);
            if(cnt >= k){
                return true;
            }
        }
        
        return cnt>=k;
        
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int max = *max_element(candies.begin(),candies.end());
        long long int sum = 0;
        
        sum = accumulate(candies.begin(),candies.end(),sum);
        
        if(sum < k) 
            return 0;
        
        if(k==1){
           return max; 
        }
        int low = 1;
        int high = max;
        int ans = 0;
        
        while(low<=high){
            int mid  = low + (high-low)/2;
            if(mid!=0 && check(candies,k,mid)){
                low = mid+1;
                ans = mid;
            }else{
                high = mid-1;
            }
        }
        return ans;
        
    }
};
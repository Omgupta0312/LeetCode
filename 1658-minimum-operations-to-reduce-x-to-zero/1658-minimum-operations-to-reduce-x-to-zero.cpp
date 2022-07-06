class Solution {
public:
//     int helper(vector<int>&v,int i,int j,int x)
//     {
//         if(x==0)
//             return 0;
        
//         if((i>=v.size() || j<0) ||(x<0) || (x-v[i] <0 && x-v[j]<0) || (i>j))
//             return INT_MAX;
        
//         int res = min(helper(v,i+1,j,x-v[i]),helper(v,i,j-1,x-v[j]));
//         return res==INT_MAX?INT_MAX:res+1;
        
//     }
    
    int minOperations(vector<int>& nums, int x) {
        int s = accumulate(nums.begin(), nums.end(), 0); // total sum of the array
        int k = s - x;                                   // target sum
        int m = INT_MIN;                                 // max length
        int n = nums.size();                             // size of the array
        int curr_sum = 0;                                // sum of the elements in the window
        int i = 0;                                       // starting point of window
        for (int j = 0; j < n; j++)                      // j = ending point of window
        {
            curr_sum += nums[j];
            while (i <= j && curr_sum > k)
            {
                curr_sum -= nums[i];
                i++;
            }
            if (curr_sum == k)
            {
                m = max(m, j - i + 1);
            }
        }
        return (m == INT_MIN) ? -1 : n - m;
    
    }
};
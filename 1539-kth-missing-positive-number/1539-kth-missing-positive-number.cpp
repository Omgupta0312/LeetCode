class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans=0;
        int j=1;
        while(arr.size()>0 && j<arr[0]){
                j++;
                k--;
                if(k==0){
                    return j-1;
                }
            }
        for(int i=0;i<arr.size();i++){
            int j = arr[i]+1;
            while(i==arr.size()-1 || (i+1<arr.size() && j<arr[i+1])){
                j++;
                k--;
                if(k==0){
                    return j-1;
                }
            }
        }
        return ans;
    }
};
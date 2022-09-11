class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> a(intervals.size(),0),b(intervals.size(),0);
        for(int i=0;i<intervals.size();i++)
            a[i]=intervals[i][0],b[i]=intervals[i][1];
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        int ans=1,iv=0,i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<=b[j])
            {
                i++;
                iv++;
            }
            else{
                iv--;
                j++;
            }
            ans=max(ans,iv);
        }
        return ans;
    }
};
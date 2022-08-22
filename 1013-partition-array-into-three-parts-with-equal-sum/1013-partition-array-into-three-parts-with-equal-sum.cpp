class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        for(auto &x:arr)
            sum+=x;
        
        if(sum%3!=0)
            return false;

        sum/=3;
        int currsum=0,count=0,i=0;
        for(i=0;i<arr.size();i++)
        {
           
            currsum+=arr[i];
            if(currsum==sum)
            {
                count++;
                currsum=0;
                    
            }
            
        }
      
        return count>=3;
        
    }
};
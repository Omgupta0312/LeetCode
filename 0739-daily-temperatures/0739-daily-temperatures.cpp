// class StockSpanner {
// public:
//     vector<int> v;
//     stack<int> s;
//     StockSpanner() {
        
//     }
    
//     int helper(int p){
//         while(!s.empty() && v[s.top()]<=p){
//             s.pop();
//         }
       
//         if(s.empty()){
//             s.push(v.size());
//             return v.size()+1;
//         }
//         int ans = v.size()-s.top();
//         s.push(v.size());
//         return ans;
//     }
//     int next(int price) {
//         int ans = helper(price);
//         v.push_back(price);
//         return ans;
//     }
// };

class Solution {
public:
    
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans; stack<int> s;
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++)
        {
            int p = temp[i];
             while(!s.empty() && temp[s.top()]<=p){
                s.pop();
            }

            if(s.empty()){
                s.push(i);
                ans.push_back(0);
            }
            else{
                int a = i-s.top();
                s.push(i);
                ans.push_back(a);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    int minSetSize(vector<int>& arr) {
//         unordered_map<int,int> m;
//         for(auto x:arr)
//             m[x]++;
//         int x = arr.size();
//         if(m.size()==1 || m.size()==2) return 1;
//         if(m.size()==x) return x/2;
        
      
//         unordered_map<int,int> m2;
//         for(auto it=m.begin();it!=m.end();it++)
//             m2[it->second]++;
        
//         if(m2.find(x/2)!=m.end()) return 1;
         unordered_map<int, int> countMap;
        priority_queue<int> countValues;
        
        for (int num : arr) countMap[num]++;
        for (auto pair: countMap) countValues.push(pair.second);    

        int size = arr.size(), result = 0;
        while (size > arr.size() / 2) {
            size -= countValues.top();
            countValues.pop();
            result++;
        }

        return result;
         
    }
};
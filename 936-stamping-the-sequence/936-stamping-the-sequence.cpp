class Solution {
public:
   vector<int> movesToStamp(string stamp, string target) {
        int ls = stamp.size();
        int lt = target.size();
        vector<int> ans;
        bool has_changed = true;
        int end   = lt-ls;
        
        while (has_changed) {  // made at least one conversion to '?'

            has_changed = false;
            for(int i = 0; i<=end; i++) {            // loop on target to check if stamp is possible in target or not
                bool visited = true;                 // check if match is found
                bool any_change = true;              // check if there is at least one non-visited match (all visited => no match)
                for (int j = 0; j<ls; j++) {
                    if (target[i+j] == '?') 
                        continue;  // already stampped
                    
                    if(stamp[j] != target[i+j]) {
                        visited = false;
                        break;
                    }
                    any_change = false;
                }
                if (visited && !any_change) {          // convert stampped  to '?'
                    ans.push_back(i);                  // add stamp to answer
                    
                    for (int j=0; j<ls; j++) 
                        target[i+j] = '?';
                    
                    has_changed = true;                 //  if we replace any value, we mark it true
                }
            }
        }
        // empty array case
        for(int i = 0; i<lt; i++) {
            if (target[i] != '?') 
				return {};
        }
        
        // reverse ans
        int i=0,j=ans.size() -1;
        while(i<j)
            swap(ans[i++],ans[j--]);
        
        return ans;
    }
};
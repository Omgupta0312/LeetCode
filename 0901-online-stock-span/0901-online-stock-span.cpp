class StockSpanner {
public:
    vector<int> v;
    stack<int> s;
    StockSpanner() {
        
    }
    
    int helper(int p){
        while(!s.empty() && v[s.top()]<=p){
            s.pop();
        }
       
        if(s.empty()){
            s.push(v.size());
            return v.size()+1;
        }
        int ans = v.size()-s.top();
        s.push(v.size());
        return ans;
    }
    int next(int price) {
        int ans = helper(price);
        v.push_back(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
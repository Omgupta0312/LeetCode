class MyCalendarThree {
public:
    vector<pair<int,int>> vec;
    MyCalendarThree() {
        vec.clear();
    }
    
    int book(int start, int end) {
        vec.push_back({start,1});
        vec.push_back({end,0});
        int n=vec.size();
        sort(vec.begin(),vec.end());
        int cnt=0;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            if(vec[i].second==1)
            {
                cnt++;
                mx=max(mx,cnt);
            }
            else
            {
                cnt--;
            }
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
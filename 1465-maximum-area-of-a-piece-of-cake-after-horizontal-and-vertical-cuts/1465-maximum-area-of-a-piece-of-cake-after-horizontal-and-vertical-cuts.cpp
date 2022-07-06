class Solution {
public:
    int maxArea(int h, int w, vector<int>& H, vector<int>& V) {
        int hd=0,vd=0;
        long long m=pow(10,9)+7;
        sort(H.begin(),H.end());
        sort(V.begin(),V.end());
        
        hd=max(hd,H[0]);
        vd=max(vd,V[0]);
        
        for(int i=0;i<H.size();i++)
        {
            if(i==H.size()-1)
            {
                hd=max(hd,h-H[i]);
            }
            else
                hd=max(hd,H[i+1]-H[i]);
        }
        
        for(int i=0;i<V.size();i++)
        {
            if(i==V.size()-1)
            {
                vd=max(vd,w-V[i]);
            }
            else
                vd=max(vd,V[i+1]-V[i]);
        }
        
        return ((vd%m)*(hd%m))%m;
        
    }
};
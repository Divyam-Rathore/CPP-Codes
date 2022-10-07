class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int> l(n),r(n);
        l[0]=h[0];
        r[n-1]=h[n-1];
        for(int i=1;i<n;i++)
        {
            l[i]=max(l[i-1],h[i]);
            r[n-i-1]=max(r[n-i],h[n-i-1]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
            ans+=max(0,min(l[i],r[i])-h[i]);
        return ans;
    }
};

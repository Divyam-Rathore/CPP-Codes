class Solution {
public:
    
    void topo(unordered_map<int,vector<int> > &m,vector<int> &sorted,vector<bool> &vis,int i,unordered_map<int,bool> chk,bool &flag){
        if(flag)
            return;
       vis[i]=true;
        chk[i]=true;
        for(int j=0;j<m[i].size();j++)
        {
            if(chk[m[i][j]])
            {
                flag=true;
                return;
            }
            if(!vis[m[i][j]])
                topo(m,sorted,vis,m[i][j],chk,flag);
        }
        chk[i]=false;
        sorted.push_back(i);
    }
    
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        ios_base::sync_with_stdio(false);//cin.tie(0);//cout.tie(0);
        vector<bool> vis(n,false);
        unordered_map<int,vector<int> > m;
        // unordered_map<int,unordered_map<int,bool> > chk;
        for(auto i:pre)
            m[i[0]].push_back(i[1]);
        vector<int> sorted;
        bool flag=false;
        unordered_map<int,bool> chk;
        for(int i=0;i<n;i++)
            if(!vis[i])
                topo(m,sorted,vis,i,chk,flag);
        if(flag)
            return {};
        return sorted;
    }
};

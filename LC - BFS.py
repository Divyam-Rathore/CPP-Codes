#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
#define pb push_back

void BFS (vector<vector<int> > v,int visited[],int i)
{
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        cout<<q.front();
        visited[q.front()]=1;
        int k=q.front();
        q.pop();
        for(auto a:v[k]){
          if(visited[a]==0)
          q.push(a);}
        }
    }
    


int main(){
    ios;
    vector<vector<int>  > v;
    v.pb({1,2});
    // v[0].pb(2);
    v.pb({2});
    v.pb({3,0});
    //  v[2].pb(0);
    v.pb({3});
    int visited[4]={0};
    int i;
    cin>>i;
    BFS(v,visited,i);
    
    
    return 0;
}

